#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
string p, s1, s2;
int lps[108], dp[108][108][108];
 
void LPS(){
    memset(lps, 0, sizeof(lps));
    int n = p.size(), j = 1, i = 0;
    while(j < n){
        if(p[j] == p[i]) lps[j++] = ++i;
        else if( i == 0) lps[j++] = 0;
        else i = lps[i - 1];
    }
}
 
int find_k(int i, int k){
    if(s1[i] == p[k]) return k + 1;
    while(k){
        if(s1[i] == p[k]) return k + 1;
        else if(p[k] != s1[i]){
            if(k != 0) k = lps[k - 1];
        }
    }
    return s1[i] == p[k] ? 1 : 0;
}
 
int f(int i, int j, int k){
    if(i >= s1.size() || j >= s2.size()) return dp[i][j][k] =  0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int ans = 0;
    if(s1[i] == s2[j]){
        int nk = find_k(i, k);
        if(nk != p.size()) ans = 1 + f(i + 1, j + 1, nk);
    }
    ans = max({f(i + 1, j, k), f(i, j + 1, k), ans});
    return dp[i][j][k] = ans;
}
 
void build(int i, int j, int k){
    if(i >= s1.size() || j >= s2.size()) return;
    if(s1[i] == s2[j]){
        int nk = find_k(i, k);
        if(nk != p.size() && dp[i][j][k] == dp[i + 1][j + 1][nk] + 1){
            cout << s1[i];
            build(i + 1, j + 1, nk);
            return;
        }
    }
    if(dp[i][j][k] == dp[i + 1][j][k]){build(i + 1, j, k); return;}
    if(dp[i][j][k] == dp[i][j + 1][k]){build(i, j + 1, k); return;}
}
 
int main(){
    cin >> s1 >> s2 >> p;
    LPS();
    memset(dp, -1, sizeof(dp));
    //cout << f(0, 0, 0) << endl;
    if(!f(0, 0, 0)) cout << 0 << endl;
    else{ build(0, 0, 0); cout << endl;}
    return 0;
}