#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
string txt, p;
int lps[100000];
vector<vector<int>> memo;
int memoj[100005][26];

void LPS(){
    memset(lps, 0, sizeof(lps));
    int n = p.size(), j = 1, i = 0;
    while(j < n){
        if(p[j] == p[i]) lps[j++] = ++i;
        else if( i == 0) lps[j++] = 0;
        else i = lps[i - 1];
    }
}

int find_j(int j, char c){
    if(j == p.size()) j = lps[j - 1];
    else if(c == p[j]) return j + 1;
    while(j){
        if(memoj[j][c - 'a'] != -1) return memoj[j][c - 'a'];
        if(c == p[j]) return j + 1;
        else if(p[j] != c){
            if(j != 0) j = lps[j - 1];
        }
    }
    return c == p[j] ? 1 : 0;
}

void find(){
    for(int i = 0; i <= p.size(); i++)
        for(int c = 0; c < 26; c++)
            memoj[i][c] = find_j(i, c + 'a');
}

int dp(int i, int j){
    int in = j == p.size() ? 1 : 0;
    
    if(i >= txt.size()) return in;
    if(memo[i][j] != -1) return memo[i][j];
   
    int ans = 0;
    if(txt[i] == '?')
        for(int c = 0; c < 26; c++) ans = max(ans, in + dp(i + 1, memoj[j][c]));
    else ans = in + dp(i + 1, memoj[j][txt[i] - 'a']);
    return memo[i][j] = ans;
}

int main(){
    io_boost;
    cin >> txt >> p;
    memo.resize(txt.size() + 5, vector<int>(p.size() + 5, -1));
    memset(memoj, -1, sizeof(memoj));
    LPS();
    find();
    cout << dp(0, 0) << endl;
    return 0;
}