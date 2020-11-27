#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, k, q;
string txt, w;
lli MOD = 1e9 + 7;
pair<lli, lli> h[1000005], b[1000005]; 
set<pair<lli, lli>> names;
map<pair<lli, lli>, int> namesm;

void build_hash_array(){
    h[0].second = h[0].first = 0;
    h[1].second = h[1].first = (txt[0] - 'a' + 1);
    b[0].second = b[0].first = 1;
    for(int i = 1; i < txt.size(); i++){
        h[i + 1].first = ((h[i].first * 26) % MOD + (txt[i] - 'a' + 1LL)) % MOD;
        h[i + 1].second = ((h[i].second * 31) % MOD + (txt[i] - 'a' + 1LL)) % MOD;
        b[i].first = (26 * b[i - 1].first) % MOD;
        b[i].second = (31 * b[i - 1].second) % MOD;   
    }
}

pair<lli, lli> get_hash(int l, int r){
    return {(h[r + 1].first - ((h[l].first * b[r - l + 1].first) % MOD) + MOD) % MOD,
            (h[r + 1].second - ((h[l].second * b[r - l + 1].second) % MOD) + MOD) % MOD};
}

pair<lli, lli> get_hash(string &w){
    lli hash_26 = (w[0] - 'a' + 1), hash_31 = (w[0] - 'a' + 1);
    for(int i = 1; i < w.size(); i++){
        hash_26 = ((hash_26 * 26) % MOD + (w[i] - 'a' + 1LL)) % MOD;
        hash_31 = ((hash_31 * 31) % MOD + (w[i] - 'a' + 1LL)) % MOD;
    }
    return {hash_26, hash_31};
}

int main(){
    io_boost;
    cin >> n >> k >> txt >> q;
    for(int i = 0; i < q; i++){
        cin >> w;
        pair<lli, lli> hash = get_hash(w);
        names.insert(hash);
        namesm[hash] = i + 1;
    }
    build_hash_array();
    bool ok = false;
    for(int i = 0; i <= k - 1; i++){
        int l = txt.size() - (k - i), r = i;
        bool f = true;
        set<pair<lli, lli>> t;
        vector<int> ans;
        for(int h = r; h < l; h+=k){
            pair<lli, lli> hash = get_hash(h, h + k - 1);
            if(names.find(hash) == names.end() || t.find(hash) != t.end()){
                f = false;
                break;
            }
            t.insert(hash);
            ans.push_back(namesm[hash]);
        }
        if(f){
            pair<lli, lli> hash = get_hash(l, txt.size() - 1);
            if(r > 0){
                pair<lli, lli> hash2 = get_hash(0, r - 1);
                hash = {((hash.first * b[r].first) % MOD + hash2.first) % MOD, ((hash.second * b[r].second) % MOD + hash2.second) % MOD};
            }       
            if(t.find(hash) == t.end() && names.find(hash) != names.end()){
                ok = true;
                cout << "YES" << endl;
                for(int pos: ans) cout << pos << " ";
                cout << namesm[hash] << endl;
                break;
            }
        }
    }
    if(!ok) cout << "NO" << endl;
    return 0;
}