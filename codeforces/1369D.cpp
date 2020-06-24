#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

const lli mod = 1e9 + 7;
lli dp[2000001];
int t, n;

int main(){
    io_boost;
    dp[0] = dp[1] = dp[2] = 0;
    dp[3] = 4;
    for(int i = 4; i <= 2000000; i++){
        if(i % 3 == 0) dp[i] = ((2 * dp[i - 2] % mod) % mod + dp[i - 1] % mod + 4) % mod;
        else dp[i] = ((2 * dp[i - 2] % mod) % mod + dp[i - 1] % mod) % mod;
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}