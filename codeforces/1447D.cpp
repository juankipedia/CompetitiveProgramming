#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m;
string A, B;
int dp[5005][5005];
int r = 0;

int LCS(int i, int j){
    if(i >= n || j >= m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if(A[i] == B[j]) ans = 2 + LCS(i + 1, j + 1);
    ans = max({LCS(i + 1, j) - 1, LCS(i, j + 1) - 1, ans});
    r = max(r, ans);
    return dp[i][j] = ans;
}

int main(){
    io_boost;
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    cin >> A >> B;
    LCS(0, 0);
    cout << r << endl;
    return 0;
}