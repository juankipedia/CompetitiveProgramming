#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int TRIE_LEN = 1005;
const int mod = 1000003;

string s;
int trie[TRIE_LEN][26], nodes = 1, failure[TRIE_LEN], 
    fail_out[TRIE_LEN], A, B, N;
bool end_word[TRIE_LEN];
char leet[] = {'o', 'i', '@', 'e', '@', 's', '@', 't', '@', '@'};
 
void build_bfs(){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < 26; i++){
            int v = trie[u][i];
            if(!v) trie[u][i] = trie[failure[u]][i];
            else q.push(v);
            if(!u || !v) continue;
            failure[v] = trie[failure[u]][i];
            fail_out[v] = end_word[failure[v]] ? failure[v] : fail_out[failure[v]];
        }
    }
}
 
void add(){
    int cur = 0;
    for(char c: s){
        int cc = c - 'a';
        if(!trie[cur][cc]) trie[cur][cc] = nodes++;
        cur = trie[cur][cc]; 
    }
    end_word[cur] = true;
}

bool check(int f){
    while(f){
        if(end_word[f]) return true;
        f = fail_out[f];
    }
    return false;
}

lli memo[21][2][2][2][TRIE_LEN];

lli dp(int n, bool l, bool u, bool d, int v){
    if(n > B || check(v)) return 0;
    if(memo[n][l][u][d][v] != -1) return memo[n][l][u][d][v];
    lli ans = (n >= A && l && u && d) ? 1 : 0;
    for(int i = 0; i < 26; i++){
        ans = (ans % mod + dp(n + 1, true, u, d, trie[v][i]) % mod) % mod;
        ans = (ans % mod + dp(n + 1, l, true, d, trie[v][i]) % mod) % mod;
    }
    for(int i = 0; i <= 9; i++)
        if(leet[i] != '@')
            ans = (ans % mod + dp(n + 1, l, u, true, trie[v][leet[i] - 'a']) % mod) % mod;
        else 
            ans = (ans % mod +  dp(n + 1, l, u, true, 0) % mod) % mod;
    return memo[n][l][u][d][v] = ans;
}

int main(){
    io_boost;
    while(cin >> A >> B){
        cin >> N;
        memset(memo, -1, sizeof(memo));
        memset(trie, 0, sizeof(trie));
        memset(end_word, 0, sizeof(end_word));
        memset(fail_out, 0, sizeof(fail_out));
        memset(failure, 0, sizeof(failure));
        nodes = 1;
        for(int i = 0; i < N; i++){
            cin >> s;
            add();
        }
        build_bfs();
        cout << dp(0, false, false, false, 0) << endl;
    }
    return 0;
}