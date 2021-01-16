#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int TRIE_LEN = 200 * 18 + 20;
const int oo = numeric_limits<int>::max();
string w;
int trie[TRIE_LEN][26], nodes = 1, cnt[TRIE_LEN], dp[TRIE_LEN][205], tmp[TRIE_LEN], n;


void add(string &s){
    int cur = 0;
    for(char c: s){
        int cc = c - 'A';
        if(!trie[cur][cc]) trie[cur][cc] = nodes++;
        cur = trie[cur][cc];
    }
}

void solve(int u){
    cnt[u] = 0;
    dp[u][0] = 0;
    for(int c = 0; c < 26; c++){
        int v = trie[u][c];
        if(!v) continue;
        solve(v);
        for(int i = 0; i <= cnt[u] + cnt[v]; i++) tmp[i] = -oo;
        for(int i = cnt[u]; i >= 0; i--)
            for(int j = 0; j <= cnt[v]; j++)
                tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j]);
        cnt[u] += cnt[v];
        for(int i = 0; i <= cnt[u]; i++) dp[u][i] = tmp[i];
    }
    if(!cnt[u]){
        cnt[u] = 1;
        dp[u][0] = dp[u][1] = 0;
    }
    if(u){
        for(int i = 0; i <= cnt[u]; i++)
            dp[u][i] += (i == 1) + (cnt[u] - i == 1);
    }
}

int main(){
    while(cin >> n){
        memset(cnt, 0, sizeof(cnt));
        memset(trie, 0, sizeof(trie));
        nodes = 1;
        int sum = 0;
        for(int i = 0; i < 2 * n; i++){
            cin >> w;
            add(w);
            sum += w.size();
        }
        solve(0);
        sum -= dp[0][n] - 2 * n;
        cout << n * sum << endl;
    }
    
    return 0;
}