# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N;
lli dp[3005][3005], a[3005];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];

    for(int i = N - 1; i >= 0; i--){
        for(int j = i; j < N; j++){
            int t = i + N - 1 - j;
            if(i == j) dp[i][j] = (t % 2 ? -a[i] : a[i]);
            else{
                if(t % 2) dp[i][j] = min(-a[i] + dp[i + 1][j], -a[j] + dp[i][j - 1]);
                else dp[i][j] = max(a[i] + dp[i + 1][j], a[j] + dp[i][j - 1]);
            }
        }
    }
    cout << dp[0][N - 1] << endl;
    return 0;
}