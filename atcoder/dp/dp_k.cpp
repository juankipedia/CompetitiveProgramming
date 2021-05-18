# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 105, MAXK = 1e5 + 5;
int N, K, a[MAXN], dp[MAXK];
bool dpb[MAXK];

int go(int k){
    if(k == 0) return false;
    if(dpb[k]) return dp[k];
    dpb[k] = true;
    dp[k] = 0;
    for(int i = 0; i < N; i++){
        if(k >= a[i] && !go(k - a[i]))
            dp[k] = true;
    }
    return dp[k];
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> a[i];
    memset(dpb, false, sizeof(dpb));
    if(go(K)) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}