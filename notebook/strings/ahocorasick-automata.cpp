/**
 * 
 * AHO CORASICK AUTOMATA.
 * 
 * time complexity O(|txt| + sum(|pattern_i| + matches).
 * 
 **/
 
const int TRIE_LEN = 400005; // Dictionary size * length of words
 
vector<string> dictionary;
string txt;
int trie[TRIE_LEN][26], nodes = 1, failure[TRIE_LEN], fail_out[TRIE_LEN];
bool end_word[TRIE_LEN];
 
void build_bfs(){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < 26; i++){
            int v = trie[u][i];
            // as long as there is no link to i and all links are defined for nodes above we must create the link of the automata
            // it means if the trie has not a child using i then we must create the link.
            if(!v) trie[u][i] = trie[failure[u]][i];
            else q.push(v);
            if(!u || !v) continue;
            failure[v] = trie[failure[u]][i];
            fail_out[v] = end_word[failure[v]] ? failure[v] : fail_out[failure[v]];
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
        end_word[cur] = true;
    }
    build_bfs();
}

void check(){
    int cur = 0;
    for(char c : txt){
        int cc = c - 'a';
        cur = trie[cur][cc];
        int f = cur;
        while(f){
            // do something
            f = fail_out[f];
        }
        //do something
    }
}