/**
 * 
 * TRIE.
 * (Tree of prefixes).
 * Check if t has a prefix in the set of prefixes added in add(s) function
 * 
 * time complexity add(s): O(s.size()).
 * time complexity check(t): O(t.size()).
 * 
 * 
 **/

const int TRIE_LEN = 400005; // Dictionary size * length of words
 
int trie[TRIE_LEN][26], nodes = 1;
bool end_word[TRIE_LEN];

void add(string &s){
    int cur = 0;
    for(char c: s){
        int cc = c - 'a';
        if(!trie[cur][cc]) trie[cur][cc] = nodes++;
        cur = trie[cur][cc];
    }
    end_word[cur] = true;
}

bool check(string &t){
    int cur = 0;
    for(char c: t){
        int cc = c - 'a';
        cur = trie[cur][cc];
        if(end_word[cur]) return true;
        if(!cur) return false;
    }
    return false;
}