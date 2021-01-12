#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
string txt, w;

lli MOD = 1e9 + 7;

lli h_txt[100005], b[100005], h_w[100005];
void rolling_hash(lli B, lli p){
    h_txt[0] = 0;
    h_txt[1] = (txt[0] - 'a' + 1);
    b[0] = 1;
    for(int i = 1; i < txt.size(); i++){
        h_txt[i + 1] = ((h_txt[i] * B) % p + (txt[i] - 'a' + 1LL)) % p;
        b[i] = (B * b[i - 1]) % p;   
    }

    h_w[0] = 0;
    h_w[1] = (w[0] - 'a' + 1);
    for(int i = 1; i < w.size(); i++)
        h_w[i + 1] = ((h_w[i] * B) % p + (w[i] - 'a' + 1LL)) % p;
}


lli get_hash(int l, int r, lli h[], lli p){
    return (h[r + 1] - ((h[l] * b[r - l + 1]) % p) + p) % p;
}

int main(){
    io_boost;
    int test = 0;
    while(cin >> txt >> w){
        //if(test == 300 || test == 301) cout << txt << " -juan- " << w << endl;
        //test++;
        rolling_hash(26, MOD);
        int l = 0, r;
        while(l < w.size() && w[l] == '?') l++;
        if(l == w.size()){
            if(w.size() <= txt.size()) cout << txt.size() - w.size() + 1 << endl;
            else cout << 0 << endl;
            continue;
        }
        r = l;
        while(r < w.size() && w[r] != '?') r++;
        vector<int> ans;
        for(int i = 0; i < txt.size() && (i + (r - l) - 1) < txt.size(); i++)
            if(get_hash(i, i + (r - l) - 1, h_txt, MOD) == get_hash(l, r - 1, h_w, MOD))
                if(i >= l) ans.push_back(i + (r - l) - 1);

        int offset = 0;
        while(r < w.size() && w[r] == '?'){
            offset++;
            r++;
        }
        l = r;

        while(l < w.size()){
            r = l;
            while(r < w.size() && w[r] != '?') r++;
        
            vector<int> ans_;

            for(int i: ans){
                if((i + (r - l) - 1) >= txt.size()) break;
                //cout << i << " 0000 " << endl;
                i = i + offset + 1;
                if(get_hash(i, i + (r - l) - 1, h_txt, MOD) == get_hash(l, r - 1, h_w, MOD))
                    ans_.push_back(i + (r - l) - 1);
            }

            ans.clear();
            ans = ans_;
            offset = 0;
            while(r < w.size() && w[r] == '?'){
                offset++;
                r++;
            }
            l = r;
        }

        int ansi = 0;
        for(int p: ans){
            
            if(txt.size() > offset && p < (txt.size() - offset)) ansi++;
        }

        cout << ansi << endl;
    }

    return 0;
}