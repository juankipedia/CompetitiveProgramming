# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N;
lli A[205];

int dp[205][205][205][2][2][2];
vector<int> Bv, Cv;

bool f(int i, lli B, lli C, bool b, bool c, bool d){
    if(i >= N) return dp[i][B][C][b][c][d] = (((B % 200) == (C % 200)) && b && c && d) ? 1 : 0;
    if(dp[i][B][C][b][c][d] != -1) return dp[i][B][C][b][c][d];
    bool ans = false;
    ans = ans || f(i + 1, (A[i] % 200 + B) % 200, C, true, c, true);
    ans = ans || f(i + 1, B, (A[i] % 200 + C) % 200, b, true, true);
    ans = ans || f(i + 1, (A[i] % 200 + B) % 200, (A[i] % 200 + C) % 200, true, true, d);
    ans = ans || f(i + 1, B, C, b, c, d);
    
    return dp[i][B][C][b][c][d] = (ans ? 1 : 0);
}


void g(int i, lli B, lli C, bool b, bool c, bool d){
    if(i >= N) return;
    if(dp[i + 1][(A[i] % 200 + B) % 200][C][true][c][true]){
        Bv.push_back(i + 1);
        g(i + 1, (A[i] % 200 + B) % 200, C, true, c, true);
    }
    else if(dp[i + 1][B][(A[i] % 200 + C) % 200][b][true][true]){
        Cv.push_back(i + 1);
        g(i + 1, B, (A[i] % 200 + C) % 200, b, true, true);
    }
    else if(dp[i + 1][(A[i] % 200 + B) % 200][(A[i] % 200 + C) % 200][true][true][d]){
        Bv.push_back(i + 1);
        Cv.push_back(i + 1);
        g(i + 1, (A[i] % 200 + B) % 200, (A[i] % 200 + C) % 200, true, true, d);
    }
    else g(i + 1, B, C, b, c, d);
}


int main(){
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++) cin >> A[i];
    bool ans = f(0, 0, 0, false, false, false);
    if(!ans) cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        g(0, 0, 0, false, false, false);
        cout << Bv.size() << " ";
        for(int b: Bv) cout << b << " ";
        cout << endl;
        cout << Cv.size() << " ";
        for(int c: Cv) cout << c << " ";
        cout << endl;
    }
    return 0;
}