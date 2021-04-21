# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;
int N, K, h[MAXN], dp[MAXN];

int go(int i){
    if(i == N - 1) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = numeric_limits<int>::max();
    for(int j = 1; j <= K; j++)
        if(i + j < N)
            ans = min(ans, abs(h[i] - h[i + j]) + go(i + j));
    return dp[i] = ans;
}

int main(){
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++) cin >> h[i];
    cout << go(0) << endl;
    return 0;
}