#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAX_N = 200005;
const lli MOD = 1e9 + 7;
const lli B = 26;

lli b[MAX_N];
lli hs[B][MAX_N], ht[B][MAX_N];

void rolling_hash(string &s, lli h[]){
    h[0] = 0;
    h[1] = (s[0] - 'a' + 1);
    b[0] = 1;
    for(int i = 1; i < s.size(); i++){
        h[i + 1] = ((h[i] * B) % MOD + (s[i] - 'a' + 1LL)) % MOD;
        b[i] = (B * b[i - 1]) % MOD;   
    }
}

lli get_hash(int l, int r, lli h[]){
    return (h[r + 1] - ((h[l] * b[r - l + 1]) % MOD) + MOD) % MOD;
}

int n, m, f[B];
string s, t;

int main(){
    cin >> n >> m >> s >> t;
    memset(f, -1, sizeof(f));
    for(int i = 0; i < m; i++)
        if(f[t[i] - 'a'] == -1) f[t[i] - 'a'] = i;
    
    for(int i = 0; i < 26; i++){
        string tmp = "";
        for(int j = 0; j < m; j++)
            if(t[j] - 'a' == i) tmp += 'a';
            else tmp += 'b';
        rolling_hash(tmp, ht[i]);
    }

    for(int i = 0; i < 26; i++){
        string tmp = "";
        for(int j = 0; j < n; j++)
            if(s[j] - 'a' == i) tmp += 'a';
            else tmp += 'b';
        rolling_hash(tmp, hs[i]);
    }

    vector<int> ans;
    for(int i = 0; i + t.size() - 1 < n; i++){
        bool ok = true;
        for(int j = 0; j < 26; j++){
            if(f[j] == -1) continue;
            ok = ok && get_hash(i, i + t.size() - 1, hs[s[i + f[j]] - 'a']) == get_hash(0, t.size() - 1, ht[j]) 
                    && get_hash(i, i + t.size() - 1, hs[j]) == get_hash(0, t.size() - 1, ht[s[i + f[j]] - 'a']) ;
        }
        if(ok) ans.push_back(i + 1);
    }
    cout << ans.size() << endl;    
    for(int p: ans) cout << p << " ";
    cout << endl;
    return 0;
}