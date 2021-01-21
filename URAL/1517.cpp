#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli MOD = 1e9 + 7;
int n;
string s, t;


pair<lli, lli> h_s[100005], b[100005], h_t[100005];


void build_hash_array(){
    h_s[0].second = h_s[0].first = 0;
    h_s[1].second = h_s[1].first = (s[0] - 'A' + 1);
    h_t[0].second = h_t[0].first = 0;
    h_t[1].second = h_t[1].first = (t[0] - 'A' + 1);

    b[0].second = b[0].first = 1;
    for(int i = 1; i < n; i++){
        h_s[i + 1].first = ((h_s[i].first * 26) % MOD + (s[i] - 'A' + 1LL)) % MOD;
        h_s[i + 1].second = ((h_s[i].second * 31) % MOD + (s[i] - 'A' + 1LL)) % MOD;

        h_t[i + 1].first = ((h_t[i].first * 26) % MOD + (t[i] - 'A' + 1LL)) % MOD;
        h_t[i + 1].second = ((h_t[i].second * 31) % MOD + (t[i] - 'A' + 1LL)) % MOD;

        b[i].first = (26 * b[i - 1].first) % MOD;
        b[i].second = (31 * b[i - 1].second) % MOD;   
    }
}

pair<lli, lli> get_hash(int l, int r, pair<lli, lli> h[]){
    return {(h[r + 1].first - ((h[l].first * b[r - l + 1].first) % MOD) + MOD) % MOD,
            (h[r + 1].second - ((h[l].second * b[r - l + 1].second) % MOD) + MOD) % MOD};
}


int main(){
    cin >> n;
    cin >> s >> t;
    build_hash_array();
    int lo = 0, hi = n, ans;
    while(lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        bool check = false;
        set<pair<lli,lli>> hashes;
        for(int i = 0; i < n && (i + mid - 1) < n; i++)
            hashes.insert(get_hash(i, i + mid - 1, h_s));

        for(int i = 0; i < n && (i + mid - 1) < n; i++){
            if(hashes.count(get_hash(i, i + mid - 1, h_t))){ 
                ans = i;
                check = true; 
                break; 
            }
        }

        if(check) lo = mid;
        else hi = mid - 1;
    }
    for(int i = ans; i < ans + lo; i++) cout << t[i];
    cout << endl;
    return 0;
}