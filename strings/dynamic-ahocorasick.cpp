/**
 * DYNAMIC AHO CORASICK
 * As long as the trie of the aho corasick cannot be modified once it built, this code
 * uses a technique to dynamize data structures that are not dynamic.
 * The idea of this technique is to store several aho corasicks of size equals to a power of two
 * and then the answer is the sum of the answer of all aho corasicks.
 * 
 * */
 
const int TRIE_LEN = 300000; // Dictionary size * length of words
const int LOG_TRIE_LEN = 20; // log2(TRIE_LEN)
 
struct Automata{
    map<int, map<int, int>> trie;
    int fail_out[TRIE_LEN];
    bool end_word[TRIE_LEN];
    vector<string> dict;
    int nodes = 1;
    bool built = false;
    void clear(){
        nodes = 1;
        built = false;
        memset(fail_out, 0, sizeof(fail_out));
        memset(end_word, 0, sizeof(end_word));
        trie.clear();
    }

    void build_bfs(){
        queue<int> q;
        q.push(0);
        int failure[TRIE_LEN] = {0};
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

    void build(){
        clear();
        built = true;
        for(string &s: dict){
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

    int check(string &s){
        int cur = 0, ans = 0;
        for(char c : s){
            int cc = c - 'a';
            cur = trie[cur][cc];
            int f = cur;
            while(f){
                if(end_word[f]) ans++;
                f = fail_out[f];
            }
        }
        return ans;
    }

};

struct DynamicAutomata{
    Automata ahos[LOG_TRIE_LEN];
    void add(string &s){
        vector<string> dict;
        dict.push_back(s);
        for(int i = 0; i < LOG_TRIE_LEN; i++){
            if(!ahos[i].dict.size()){
                std::move(dict.begin(), dict.end(), std::back_inserter(ahos[i].dict));
                break;
            }
            else{
                std::move(ahos[i].dict.begin(), ahos[i].dict.end(), std::back_inserter(dict));
                ahos[i].dict.clear();
                ahos[i].built = false;
            }
        }
    }
 
    int count(string  &s){
        int ans = 0;
        for(int i = 0; i < LOG_TRIE_LEN; i++){
            if(ahos[i].dict.size()){
                if(!ahos[i].built) ahos[i].build();
                ans += ahos[i].check(s);
            }
        }
        return ans;
    }
};

DynamicAutomata insertions, deletions;

int count(string &s){
    return insertions.count(S) - deletions.count(S);
}
