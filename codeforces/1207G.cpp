#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
 
const int TRIE_LEN = 400005; // Dictionary size * length of words
 
int n, m, t;
vector<string> dictionary;
vector<int> query[TRIE_LEN];
int ans[TRIE_LEN], counts[TRIE_LEN];
string w;
 
pair<char, vector<int>> txt[TRIE_LEN];
 
int trie[TRIE_LEN][26], nodes = 1, failure[TRIE_LEN], fail_out[TRIE_LEN], end_word[TRIE_LEN];
int end_word_map[TRIE_LEN];
 
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
            fail_out[v] = end_word[failure[v]] != -1 ? failure[v] : fail_out[failure[v]];
        }
    }
}
 
void build(){
    for(int i = 0; i < dictionary.size(); i++){
        string &s = dictionary[i];
        int cur = 0;
        for(char c: s){
            int cc = c - 'a';
            if(!trie[cur][cc]) trie[cur][cc] = nodes++;
            cur = trie[cur][cc]; 
        }
        if(end_word[cur] == -1) end_word[cur] = i;
        else end_word_map[i] = end_word[cur];
    }
    build_bfs();
}
 
int count_prefix(int cur, char c, int val){
    int cc = c - 'a';
    cur = trie[cur][cc];
    int f = cur;
    while(f){
        if(end_word[f]!= -1){
            counts[end_word[f]] += val;
        }
        f = fail_out[f];
    }
    return cur;
}
 
void dfs(int u, int cur){
    int n_cur = count_prefix(cur, txt[u].first, 1);
    for(int q: query[u]) ans[q] = counts[end_word_map[q]];
    for(int v: txt[u].second) dfs(v, n_cur);
    count_prefix(cur, txt[u].first, -1);
}
 
 
int main(){
    io_boost;
    memset(end_word, -1, sizeof(end_word));
    cin >> n;
    int ii;
    char c;
    for(int i = 1; i <= n; i++){
        cin >> t;
        if(t == 1){
            cin >> c;
            txt[0].second.push_back(i);
            txt[i] = {c, {}};
        }
        else{
            cin >> ii >> c;
            txt[ii].second.push_back(i);
            txt[i] = {c, {}};
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> ii >> w;
        end_word_map[i] = i;
        query[ii].push_back(i);
        dictionary.push_back(w);
    }
    build();
    for(int u : txt[0].second) dfs(u, 0);
    for(int i = 0; i < m; i++) cout << ans[i] << endl;
    return 0;
}