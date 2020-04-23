#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int t, n;
char k;
stack<int> s;

void dfs_(vector<int> g[], bool v[], int src, bool fill){
    if(v[src]) return;
    v[src] = true;
    for(const int &tgt: g[src])
        dfs_(g, v, tgt, fill);
    if(fill) s.push(src);
}

void dfs(vector<int> g[]){
    bool v[n];
    for(int i = 0; i < n; i++) v[i] = false;
    for(int i = 0; i < n; i++)
        if(!v[i])
            dfs_(g, v, i, true);
}

void kosaraju(vector<int> g[]){
    bool v[n];
    int src, r = 0;
    for(int i = 0; i < n; i++) v[i] = false;
    while(!s.empty()){
        src = s.top();
        s.pop();
        if(!v[src]){
            r ++;
            dfs_(g, v, src, false);
        }
    }
    cout << r << endl;
}

int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> g[n], gt[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> k;
                if(k == 'Y'){
                    g[i].push_back(j);
                    gt[j].push_back(i);
                }
            }
        }
        dfs(g);
        kosaraju(gt);
    }
    return 0;
}