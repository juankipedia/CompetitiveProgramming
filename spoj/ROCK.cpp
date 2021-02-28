# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N;
string r;

int memo[205][205];

int dp(int i, int s, int l){
    if(i == N){
        if(s > 0) return l;
        else return 0;
    }

    if(memo[i][l] != -1) return memo[i][l];

    int &ans = memo[i][l];

    if(r[i] == '1') s++;
    else s--;
    l++;
    if(s > 0) return ans = max(l + dp(i + 1, 0, 0), dp(i + 1, s, l));
    else return ans = max(dp(i + 1, 0, 0), dp(i + 1, s, l));
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> N >> r;
        memset(memo, -1, sizeof(memo));
        cout << dp(0, 0, 0) << endl;
    }
    return 0;
}