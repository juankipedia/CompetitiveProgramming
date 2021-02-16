/**
 *  KMP AUTOMATA.
 *  Find all occurrences of p in txt (pattern searching), this version is useful for dynamic programing problems.
 *  Preprocessing time complexity: O(n * vocabulary_size).
 *  Time complexity: O(n), less than normal kmp.
 **/

string txt, p;
int lps[1000000], automata[1000000][26];

void LPS(){
    memset(lps, 0, sizeof(lps));
    int n = p.size(), j = 1, i = 0;
    while(j < n){
        if(p[j] == p[i]) lps[j++] = ++i;
        else if(i == 0) lps[j++] = 0;
        else i = lps[i - 1];
    }
}

int find_k(int j, int c){
    if(j == p.size()) j = lps[j - 1];
    else if(c == (p[j] - 'a')) return j + 1;
    while(j){
        if(automata[j][c] != -1) return automata[j][c];
        if(c == (p[j] - 'a')) return j + 1;
        j = lps[j - 1];
    }
    return c == (p[j] - 'a')? 1 : 0;
}

void build_automata(){
    LPS();
    memset(automata, -1, sizeof(automata));
    for(int i = 0; i <= p.size(); i++)
        for(int j = 0; j < 26; j++)
            automata[i][j] = find_k(i, j);
}

vector<int> find_pattern(){
    build_automata();
    vector<int> ans;
    int i = 0, j = 0;
    while(i < txt.size()){
        j = automata[j][txt[i] - 'a'];
        if(j == p.size()) ans.push_back(i - j + 1);
        i++;
    }
    return ans;
}