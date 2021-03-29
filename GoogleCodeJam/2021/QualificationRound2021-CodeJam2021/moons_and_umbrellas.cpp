# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, X, Y;
string s;
int memo[1005][2];

int dp(int i, int l){
    if(i >= n) return 0;
    if(memo[i][l] != -1) return memo[i][l];
    int &ans = memo[i][l];
    if(i == 0){
        if(s[i] == '?') ans = min(dp(i + 1, 1), dp(i + 1, 0));
        else ans = dp(i + 1, s[i]  == 'C');
    }
    else {
        if(l){
            if(s[i] == '?') ans = min(dp(i + 1, 1), X + dp(i + 1, 0));
            else if(s[i] == 'C') ans = dp(i + 1, 1);
            else ans = X + dp(i + 1, 0);
        }
        else{
            if(s[i] == '?') ans = min( Y + dp(i + 1, 1), dp(i + 1, 0));
            else if(s[i] == 'C') ans = Y + dp(i + 1, 1);
            else ans = dp(i + 1, 0);
        }
    }

    return ans;
}

int main(){
    io_boost;
    int t;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> X >> Y >> s;
        n = s.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 2; j++) memo[i][j] = -1;
        cout << "Case #" << ti << ": " << dp(0, false) << endl;
    }
    return 0;
}