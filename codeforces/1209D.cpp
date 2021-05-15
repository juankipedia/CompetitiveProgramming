# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 100000;
int N, parent[MAXN];

void build(){
    for(int i = 0; i < N; i++) parent[i] = i;
}

int find(int a){
    if(parent[a] != a) parent[a] = find(parent[a]);
    return parent[a];
}

void join(int a, int b){
    parent[find(a)] = find(b); 
}

int k;

int main(){
    cin >> N >> k;
    build();
    int ans = 0;
    for(int i = 0, u, v; i < k; i++){
        cin >> u >> v;
        if(find(u) == find(v)) ans++;
        else join(u, v);
    }
    cout << ans << endl;
    return 0;
}