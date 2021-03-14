/**
 * 
 * AHO CORASICK NO SIMPLIFIED AUTOMATA.
 * 
 * time complexity O(|txt| * sqrt(sum(|pattern_i|))).
 *  
 **/

const int TRIE_LEN = 2000005; // Dictionary size * length of words


vector<string> dictionary;
vector<string> queries; // in case of single query replace this with a single string

int trie[TRIE_LEN][26], nodes = 1, failure[TRIE_LEN], fail_out[TRIE_LEN];
bool end_word[TRIE_LEN];

void build_bfs(){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < 26; i++){
            int v = trie[u][i];
            if(v){
                q.push(v);
                if(u){
                    failure[v] = failure[u];
                    while(failure[v] && !trie[failure[v]][i])
                        failure[v] = failure[failure[v]];
                    failure[v] = trie[failure[v]][i];
                    fail_out[v] = end_word[failure[v]] ? failure[v] : fail_out[failure[v]];
                }
            }   
        }
    }
}

// call build before using the automata
void build(){
    for(auto & s : dictionary){
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

// in case of single query we can iterate over the single query, instead of passing the index of the query.

void check(int i){
    int cur = 0;
    for(char c : queries[i]){
        int cc = c - 'a';

        while(cur && !trie[cur][cc]) cur = failure[cur]; // this while is the difference with the simplified one
        cur = trie[cur][cc];

        int f = fail_out[cur];
        while(f){
            if(end_word[f]); // do something
            f = fail_out[f];
        }
        //do something
    }

    return;
}