#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli oo = numeric_limits<lli>::max();
int N, C;
lli X, A[100], SM;

lli memo[100][100][100];

lli dp(int i, int j, int sm){
    if(i == N){
        if(j != C) return -1;
        if(sm != SM) return -1;
        return 0;
    }
    if(memo[i][j][sm] != -2) return memo[i][j][sm];
    lli ans = dp(i + 1, j + 1, (sm + A[i] % C) % C);
    if(ans != -1) ans += A[i];
    return memo[i][j][sm] = max(ans, dp(i + 1, j, sm));
}

int main(){
    cin >> N >> X;
    for(int i = 0; i < N; i++) cin >> A[i];
    lli ans = oo;
    for(C = 1; C <= N; C++){
        SM = X % C;
        for(int i = 0; i < 100; i++)
            for(int j = 0; j < 100; j++)
                for(int k = 0; k < 100; k++)
                    memo[i][j][k] = -2;
        lli r = dp(0, 0, 0);
        if(r != -1) ans = min(ans, (X - r) / C);
    }
    cout << ans << endl;
    return 0;
}