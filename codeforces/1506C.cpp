# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string a, b;
int memo[25][25][25][25];

bool equal(int i, int j, int k, int w){
    if((j - i) != (w - k)) return false;
    for(int l = 0; l <= (j - i); l++)
        if(a[i + l] != b[k + l]) return false;
    return true;
}

int dp(int i, int j, int k, int w){
    if(i == j && k == w ){
        if(equal(i, j, k, w)) return 0;
        else return 2;
    }
    if(equal(i, j, k, w)) return 0;
    if(memo[i][j][k][w] != -1)
        return memo[i][j][k][w];
    int ans;
    if(i == j){
        ans =  min(1 + dp(i, j, k + 1, w), 1 + dp(i, j, k, w - 1));
    }
    else if(k == w){
        ans = min(1 + dp(i + 1, j, k, w), 1 + dp(i, j - 1, k, w ));
    }
    else{
        ans = min({
            1 + dp(i + 1, j, k , w),
            1 + dp(i, j - 1, k, w),
            1 + dp(i, j, k + 1, w),
            1 + dp(i, j, k, w - 1)
        });
    }
    return memo[i][j][k][w] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        for(int i = 0; i < 25; i++)
        for(int j = 0; j < 25; j++)
        for(int k = 0; k < 25; k++)
        for(int w = 0; w < 25; w++) memo[i][j][k][w] = -1;
        cout << dp(0, a.size() - 1, 0, b.size() - 1) << endl;
    }
    return 0;
}