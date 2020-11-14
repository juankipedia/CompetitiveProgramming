#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
 
const int TRIE_LEN = 300005;
 
string w, s;
int nodes = 1, N, T;
lli ans, cnt[TRIE_LEN];
map<char, int> trie[TRIE_LEN];

void add(){
    int cur = 0;
    for(char c: s){
        int cc = c - 'a';
        if(trie[cur].find(cc) == trie[cur].end()) trie[cur][cc] = nodes++;
        cur = trie[cur][cc]; 
        cnt[cur]++;
    }
}

int calc(int v, lli h){
    lli c = 0;
    for(auto &p : trie[v])
        c += calc(p.second, h + 1);
    cnt[v] -= c;
    lli m = cnt[v] / 2;
    if(m > 0){
        ans += (h / 2) * (h / 2) * m;
        return c + m * 2;
    }
    return c;
}

int main(){
    io_boost;
    cin >> T;
    while(T--){
        cin >> N;
        ans = 0;
        for(int i = 0; i < nodes; i++)
            trie[i].clear(), cnt[i] = 0;
        nodes = 1;
        for(int i = 0; i < N; i++){
            cin >> w;
            s = "";
            for(int j = 0, k = w.size() - 1; j < w.size(); j++, k--)
                s += w[j], s += w[k];
            add();
        }
        calc(0, 0);
        cout << ans << endl;
    }
    return 0;
}