#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const short int oo = 200;
const int TRIE_LEN = 22e4; // Dictionary size * length of words
 
int n;
string txt, w, dictionary[50000];
int trie[TRIE_LEN][26], nodes = 1, end_word[TRIE_LEN];
short int memo[100][TRIE_LEN];

string dial[] = {"oqz", "ij", "abc", "def", "gh", "kl", "mn", "prs", "tuv", "wxy"};

 
void add(string &s, int idx){
    int cur = 0;
    for(char c: s){
        int cc = c - 'a';
        if(!trie[cur][cc]) trie[cur][cc] = nodes++;
        cur = trie[cur][cc]; 
    }
    end_word[cur] = idx;
}

short int dp(int i, int j){
    if(i >= txt.size()) return memo[i][j] = end_word[j] != -1 ? 1 : oo;
    if(memo[i][j] != -1) return memo[i][j];
    short int ans = oo;
    short int one = 1;
    for(char c : dial[txt[i] - '0']){
        int cc = c - 'a';
        if(end_word[j] != -1) ans = min(short(1 + dp(i, 0)), ans);
        if(trie[j][cc]) ans = min(dp(i + 1, trie[j][cc]), ans);
    }
    return memo[i][j] = ans;
}

void build(int i, int j){
    if(i >= txt.size()){
        if(end_word[j] != -1) cout << dictionary[end_word[j]] << " ";
        return;
    }
    for(char c : dial[txt[i] - '0']){
        int cc = c - 'a';
        if(end_word[j] != -1){
            if(memo[i][j] == (memo[i][0] + 1)){
                cout << dictionary[end_word[j]] << " ";
                build(i, 0);
                return;
            }
        }
        if(trie[j][cc]){
            if(memo[i][j] == memo[i + 1][trie[j][cc]]){
                build(i + 1, trie[j][cc]);
                return;
            }
        }
    }
    return;
}

int main(){
    io_boost;
    while(cin >> txt && txt != "-1"){
        memset(end_word, -1, sizeof(end_word));
        memset(memo, -1, sizeof(memo));
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> dictionary[i];
            add(dictionary[i], i);
        }
        int ans = dp(0, 0);
        if(ans >= oo) cout << "No solution." << endl;
        else{
            build(0, 0);
            cout << endl;
        }
    }
    return 0;
}