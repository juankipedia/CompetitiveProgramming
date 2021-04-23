# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int N, M;
string s, t;
int dp[3000][3000];
 
int go(int i, int j){
    if(i >= N || j >= M) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if(s[i] == t[j]) ans = 1 + go(i + 1, j + 1);
    else ans = max(go(i + 1, j), go(i, j + 1));
    return dp[i][j] = ans;
}
 
void pgo(int i, int j, int len){
    if(i >= N || j >= M) return;
    if(s[i] == t[j]){
        cout << s[i];
        pgo(i + 1, j + 1, len - 1);
    }
    else{
        if(dp[i + 1][j] == len) pgo(i + 1, j, len);
        else pgo(i, j + 1, len);
    }
}
 
 
int main(){
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    N = s.size();
    M = t.size();
    int len = go(0, 0);
    pgo(0, 0, len);
    cout << endl;
    return 0;
}