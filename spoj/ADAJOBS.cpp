#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<string, int> word_time;

const int MAXN = 2000005;

int n, type;
vector<word_time> adds, queries;
string w;

int trie[MAXN][26], nodes = 1, end_time[MAXN], failure[MAXN], fail_out[MAXN];

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
                    fail_out[v] = end_time[failure[v]] ? failure[v] : fail_out[failure[v]];
                }
            }   
        }
    }
}

void build(){
    for(auto & p : adds){
        string &s = p.first;
        int cur = 0;
        for(char c: s){
            int cc = c - 'a';
            if(!trie[cur][cc]) trie[cur][cc] = nodes++;
            cur = trie[cur][cc]; 
        }
        if(!end_time[cur]) end_time[cur] = p.second;
    }
    build_bfs();
}

bool check(int i){
    int cur = 0;
    for(char c : queries[i].first){
        int cc = c - 'a';

        while(cur && !trie[cur][cc]) cur = failure[cur];
        cur = trie[cur][cc];

        int f = fail_out[cur];
        while(f){
            if(end_time[f] && end_time[f] < queries[i].second) return true;
            f = fail_out[f];
        }
        if(end_time[cur] && end_time[cur] < queries[i].second) return true;
    }

    return false;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> type >> w;
        if(type == 0) adds.push_back({w, i});
        else queries.push_back({w, i});   
    }
    build();
    for(int i = 0; i < queries.size(); i++)
        if(check(i)) cout << "YES" << endl;
        else cout << "NO" << endl;
    return 0;
}