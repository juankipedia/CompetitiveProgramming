#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
 
const int TRIE_LEN = 6000005;
 
string txt, si;
int trie[TRIE_LEN][26], nodes = 1, failure[TRIE_LEN], fail_out[TRIE_LEN], end_word[TRIE_LEN], word[TRIE_LEN];

int A, B, Q;

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
 
void add(string &s, int i){
    int cur = 0;
    for(char c: s){
        int cc = c - 'a';
        if(!trie[cur][cc]) trie[cur][cc] = nodes++;
        cur = trie[cur][cc]; 
    }
    end_word[cur] = 0;
    word[i] = cur;
}

int check(){
    int cur = 0;
    for(char c : txt){
        int cc = c - 'a';
        cur = trie[cur][cc];
        int f = cur;
        while(f){
            if(end_word[f] != -1) end_word[f]++;
            f = fail_out[f];
        }
    }
    return cur;
}

int main(){
    io_boost;
    memset(end_word, -1, sizeof(end_word));
    cin >> txt;
    cin >> Q >>  A >> B;
    for(int i = 0; i < Q; i++){
        cin >> si;
        add(si, i);
    }
    build_bfs();
    int cur = check();
    int ans = end_word[word[0]];
    cout << ans << endl;
    for(int i = 1; i < Q; i++){
        int cc = ((A * ans + B) % 26);
        cur = trie[cur][cc];
        int f = cur;
        while(f){
            if(end_word[f] != -1) end_word[f]++;
            f = fail_out[f];
        }
        ans = end_word[word[i]];
        cout << ans << endl;
    }
    return 0;
}