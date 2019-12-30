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

int n;
lli a[200001], dp[200001], pd[200001];
int main(){
    io_boost;
    cin >> n;

    lli maxi = 1;
    dp[0] = 1;
    cin >> a[0];
    for(int i = 1; i < n; i++){
        cin >> a[i];
        if(a[i] > a[i-1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = 1;
        maxi = max(maxi, dp[i]);
    }
    pd[n - 1] = 1;
    for(int i = n-2; i >= 0; i--)
        if(a[i] < a[i + 1])
            pd[i] = pd[i+1] + 1;
        else
            pd[i] = 1;
 
    for(int i = 1; i < n-1; i++)
        if(a[i+1] > a[i-1])
            maxi = max(maxi, (pd[i + 1] + dp[i - 1]));
 
    cout<< maxi <<endl;
    return 0;
}