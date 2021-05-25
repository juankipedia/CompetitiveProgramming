# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXM = (1 << 21);
const int MOD = 1e9 + 7;
int N;
bool a[25][25];
lli dp[25][MAXM];

lli go(int i, ulli m){
    if(i >= N) return 1;
    if(dp[i][m] != -1) return dp[i][m];
    lli ans = 0;
    for(int j = 0; j < N; j++){
        if(a[i][j] && !((1 << j) & m))
            ans = (ans + go(i + 1, ((1 << j) | m))) % MOD;
    }
    return dp[i][m] = ans;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> a[i][j];
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << endl;
    return 0;
}