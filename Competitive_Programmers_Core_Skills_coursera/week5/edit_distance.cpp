#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> v_i;
typedef vector<long long int> v_lli;
typedef vector<unsigned int> v_ui;
typedef vector<unsigned long long int> v_ulli;
typedef set<int> s_i;
typedef set<long long int> s_lli;
typedef set<unsigned int> s_ui;
typedef set<unsigned long long int> s_ulli;
typedef unordered_set<int> u_s_i;
typedef unordered_set<long long int> u_s_lli;
typedef unordered_set<unsigned int> u_s_ui;
typedef unordered_set<unsigned long long int> u_s_ulli;

int I, D, S;
map<string, int> T;

int min(int x, int y, int z) { 
    return min(min(x, y), z); 
} 
  
int editDistDP(string str1, string str2, int m, int n) { 
    int dp[m+1][n+1]; 
    for (int i=0; i<=m; i++) { 
        for (int j=0; j<=n; j++) {  
            if (i==0) 
                dp[i][j] = j * I;  
            else if (j==0) 
                dp[i][j] = i * D; 
            else if (str1[i-1] == str2[j-1]) 
                dp[i][j] = dp[i-1][j-1]; 
            else
                dp[i][j] = min(dp[i][j-1] + I, dp[i-1][j] + D, dp[i-1][j-1] + S);
        } 
    } 
    return dp[m][n]; 
} 


int main() {
    int n, m;
    string a, b;
    cin >> n >> m;
    cin >> a >> b;
    cin >> I >> D >> S;
    cout << editDistDP(a, b, n, m) << endl;
    return 0;
}
