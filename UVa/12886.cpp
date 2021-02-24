#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli MOD = 1000000007;
int wp, hp, wt, ht;
string p[2005], txt[2005];
lli Hp[2005][2005], Ht[2005][2005], b[2005];

void rolling_hash(string &s, lli h[], lli b[], lli B, lli p){
    h[0] = 0;
    h[1] = (s[0] - 'a' + 1);
    b[0] = 1;
    for(int i = 1; i < s.size(); i++){
        h[i + 1] = ((h[i] * B) % p + (s[i] - 'a' + 1LL)) % p;
        b[i] = (B * b[i - 1]) % p;   
    }
}

lli get_hash(int l, int r, lli h[], lli b[], lli p){
    return (h[r + 1] - ((h[l] * b[r - l + 1]) % p) + p) % p;
}

int lps[2005];

void LPS(vector<lli> &p){
    memset(lps, 0, sizeof(lps));
    int n = p.size(), j = 1, i = 0;
    while(j < n){
        if(p[j] == p[i]) lps[j++] = ++i;
        else if(i == 0) lps[j++] = 0;
        else i = lps[i - 1];
    }
}

int find_pattern(vector<lli> &p, vector<lli> &txt){
    LPS(p);
    int ans = 0;
    int i = 0, j = 0;
    while(i < txt.size()){
        if(txt[i] == p[j]){j++; i++;}
        if(j == p.size()){
            ans++;
            j = lps[j - 1];
        }
        else if(i < txt.size() && p[j] != txt[i]){
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return ans;
}

int main(){
    while(cin >> hp >> wp >> ht >> wt){
        for(int i = 0; i < hp; i++){
            cin >> p[i];
            rolling_hash(p[i], Hp[i], b, 2, MOD);
        }
        for(int i = 0; i < ht; i++){
            cin >> txt[i];
            rolling_hash(txt[i], Ht[i], b, 2, MOD);
        }
        vector<vector<lli>> mt;
        vector<lli> mp;
        for(int j = 0; (j + wp - 1) < wt; j++){
            mt.push_back({});

            for(int i = 0; i < ht; i++)
                mt[j].push_back(get_hash(j, j + wp - 1, Ht[i], b, MOD));
        }
        for(int i = 0; i < hp; i++) mp.push_back(get_hash(0, wp - 1, Hp[i], b, MOD));
        int ans = 0;
        for(int i = 0; i < mt.size(); i++) ans += find_pattern(mp, mt[i]);
        cout << ans << endl;
    }
    return 0;
}