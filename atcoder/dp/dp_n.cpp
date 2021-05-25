# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 400;
const lli oo = numeric_limits<lli>::max();

int N;
lli a[MAXN], dp[MAXN][MAXN];

lli g(int i, int j){
    lli sum = 0;
    for(int l = i; l <= j; l++) sum += a[l];
    return sum;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
   
    for(int i = N - 1; i >= 0; i--){
        for(int j = i + 1; j < N; j++){
            dp[i][j] = oo;
            for(int l = i; l < j; l++){
                lli a = g(i, l), b = g(l + 1, j);
                dp[i][j] = min(dp[i][j], dp[i][l] + dp[l + 1][j] + a + b);
            }
        }
    }
    cout << dp[0][N - 1] << endl;
    return 0;
}