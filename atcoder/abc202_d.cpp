# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

ulli dp[35][35], A, B, K;

void go(ulli A, ulli B, ulli K){
    if(A == 0 && B == 0) return;
    if(A == 0){
        cout << 'b';
        go(A, B - 1, K);
        return;
    }
    if(B == 0){
        cout << 'a';
        go(A - 1, B, K);
        return;
    }
    if(dp[A - 1][B] >= K){
        cout << 'a';
        go(A - 1, B, K);
        return;
    }
    else{
        cout << 'b';
        go(A, B - 1, K - dp[A - 1][B]);
        return;
    }
}

int main(){
    cin >> A >> B >> K;
    dp[0][0] = 1;
    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            if(i > 0) dp[i][j] += dp[i - 1][j];
            if(j > 0) dp[i][j] += dp[i][j - 1];
        }
    }

    go(A, B, K);
    cout << endl;
    return 0;
}