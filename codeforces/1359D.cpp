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

int n, a[100000], ans, memo[62][100000];
bool memot[62][100000];

int dp(int mx, int i){
    if(i >= n)
        return 0;
    if(memot[mx + 30][i]) return memo[mx + 30][i];
    memot[mx + 30][i] = true;
    int maxi = 0;
    if(mx == 31)
        maxi = max(0, dp(a[i], i + 1));
    else if(a[i] > mx)
        maxi = max(0, dp(a[i], i + 1) + mx);
    else
        maxi = max(0, dp(mx, i + 1) + a[i]);
    
    memo[mx + 30][i] = maxi;
    return maxi;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) ans = max(ans, dp(31, i));

    cout << ans << endl;
    return 0;
}