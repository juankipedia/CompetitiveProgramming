#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 300005; // Dictionary size * length of words

int n, m, type, in;
lli  x;
vector<string> dictionary;
string w;

vector<string> queries; // in case of single query replace this with a single string

int trie[MAXN][26], nodes = 1, failure[MAXN], fail_out[MAXN];
multiset<lli> end_word[MAXN];
int end_node[MAXN];
lli suspicion[MAXN];



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
                    fail_out[v] = end_word[failure[v]].size() ? failure[v] : fail_out[failure[v]];
                }
            }   
        }
    }
}

void build(){
    for(int i = 0; i < n; i++){
        auto &s = dictionary[i];
        int cur = 0;
        for(char c: s){
            int cc = c - 'a';
            if(!trie[cur][cc]) trie[cur][cc] = nodes++;
            cur = trie[cur][cc]; 
        }
        end_word[cur].insert(0);
        end_node[i] = cur;
    }
    build_bfs();
}


lli check(string &s){
    int cur = 0;
    lli ans = -1;
    for(char c : s){
        int cc = c - 'a';

        while(cur && !trie[cur][cc]) cur = failure[cur];
        cur = trie[cur][cc];

        int f = fail_out[cur];
        lli maxi = end_word[cur].size() ? *end_word[cur].rbegin() : -1;
        while(f){
            maxi = max(maxi, end_word[f].size() ? *end_word[f].rbegin() : -1);
            f = fail_out[f];
        }

        ans = max(maxi, ans);
    }

    return ans;
}


int main(){
    io_boost;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> w, dictionary.push_back(w);
    build();
    for(int i = 0; i < m; i++){
        cin >> type;
        if(type == 1){
            cin >> in >> x;
            in --;
            auto it = end_word[end_node[in]].find(suspicion[in]);
            if(it != end_word[end_node[in]].end())
                end_word[end_node[in]].erase(it);
            suspicion[in] = x;
            end_word[end_node[in]].insert(suspicion[in]);
        }
        else{
            cin >> w;
            cout << check(w) << endl;
        }
    }

    return 0;
}