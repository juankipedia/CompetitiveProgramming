#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

unsigned int n;
string vocab, p;
int lps[51], automata[51][26];

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

typedef vector<vector<unsigned int>> matrix;

void multiply(matrix &m1, matrix &m2, matrix &res){
    int N = m1.size(), K = m1[0].size(), M = m2[0].size();
    unsigned int a[N][K], b[K][M];
    for(int i = 0; i < N; i++) for(int j = 0; j < K; j++) a[i][j] = m1[i][j];
    for(int i = 0; i < K; i++) for(int j = 0; j < M; j++) b[i][j] = m2[i][j];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            unsigned int val = 0;
            for(int k = 0; k < K; k++) val += a[i][k] * b[k][j];
            res[i][j] = val;
        }
    }
}

void matrix_power(matrix &m, unsigned int r){
    int N = m.size();
    matrix cur(N, vector<unsigned int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cur[i][j] = m[i][j];
            if(i == j) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
    while(r){
        if(r % 2ULL == 1) multiply(m, cur, m);
        multiply(cur, cur, cur);
        r /= 2;
    }
}

int main(){
    int t;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> n;
        cin >> vocab >> p;
        bool v[26] = {false};
        for(int i = 0; i < vocab.size(); i++) v[vocab[i] - 'a'] = true;
        build_automata();
        matrix g(p.size(), vector<unsigned int>(p.size(), 0));
        for(int i = 0; i < p.size(); i++)
            for(int j = 0; j < 26; j++)
                if(automata[i][j] != p.size() && v[j])
                    g[i][automata[i][j]]++;
        matrix_power(g, n);
        unsigned int ans = 0;
        for(int i = 0; i < p.size(); i++) ans += g[0][i];
        cout << "Case " << ti << ": " << ans << endl;
    }
    return 0;
}