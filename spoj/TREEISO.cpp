#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ulli random(ulli a, ulli b){
    return uniform_int_distribution<ulli>(a, b)(rng);
}
map<ulli, ulli> hash_map;
ulli g(ulli x){
    if(hash_map.count(x)) return hash_map[x];
    else return hash_map[x] = random(0, 1e18);
}

int t, n;
vector<int> t1[100000], t2[100000];

vector<int> find_root(vector<int> g[]){
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto v : g[u]) if (v != prev) {
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > n / 2) is_centroid = false;
        }
        if (n - sz[u] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}

ulli get_hash(int u, int p, vector<int> t[]){
    ulli hash_sum = 0;
    for(int v: t[u])
        if(v != p)
            hash_sum += get_hash(v, u, t);
    return g(hash_sum); 
}

int main(){
    io_boost;
    cin >> t;
    while(t--){        
        cin >> n;
        for(int i = 0; i < n; i++) t1[i].clear(), t2[i].clear();
        int u, v;
        for(int i = 0; i < n - 1; i++){
            cin >> u >> v;
            u--; v--;
            t1[u].push_back(v);
            t1[v].push_back(u);
        }
        for(int i = 0; i < n - 1; i++){
            cin >> u >> v;
            u--; v--;
            t2[u].push_back(v);
            t2[v].push_back(u);
        }

        vector<int> roots1 = find_root(t1);
        vector<int> roots2 = find_root(t2);
        bool f = false;
        for(int r1: roots1){
            for(int r2: roots2){
                if(get_hash(r1, -1, t1) == get_hash(r2, -1, t2)){
                    cout << "YES" << endl;
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
        if(!f) cout << "NO" << endl;
    }
    return 0;
}