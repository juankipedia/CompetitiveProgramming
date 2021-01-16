#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;
int N, M, begin, k;
int g[MAXN];
bool visited[MAXN], zero[MAXN];
vector<pair<int, int>> components;

void dp(int v){
    if(visited[v]){
        components[k].second = v;
        return;
    }
    visited[v] = true;
    dp(g[v]);
}

int main(){
    cin >> N;
    int cc = 0;

    for(int u = 0, v; u < N; u++){
        cin >> v; v--;
        g[u] = v;
        zero[v] = true;
    }
    for(int i = 0; i < N; i++){
        if(!zero[i]){
            components.push_back({i, -1});
            dp(i);
            k++;
        }
    }
    bool f = false;
    if(k == 0) f = true;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            components.push_back({i, -1});
            dp(i);
            k++;
        }
    }
    if(f and k == 1) cout << 0 << endl;
    else{
        cout << k << endl;
        for(int i = 0; i < k; i++)
            cout << components[i].second + 1 << " " << components[(i + 1) % k].first + 1 << endl;
    }
    return 0;
}