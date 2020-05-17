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

class Edge{ 
public:
    int src, tgt, cost;
    Edge(int s, int t, int c): src(s), tgt(t), cost(c) {}
};

const int INF = std::numeric_limits<int>::max();
int N, M, U, V, C, cans, wans;

int find(int parents[], int u){
    if(parents[u] != u)
        parents[u] = find(parents, parents[u]);
    return parents[u];
}

void Union(int parents[], int u, int v){
    parents[find(parents, u)] = find(parents, v); 
}


int kruskal_(vector<Edge> &edges, int iu, int iv){
    int parents[N];
    for(int i = 0; i < N; i++) parents[i] = i;
    int e = 0, u, v, c, W = 0, r = 0;
    while (e < M && r < N - 1){
        u = edges[e].src; v = edges[e].tgt; c = edges[e].cost;
        if(u == iu && v == iv || u == iv && v == iu){
            e++; continue;
        }
        u = find(parents, u); v = find(parents, v);
        if(u != v){
            W += c;
            Union(parents, u, v);
            r++;
        }
        e++;
    }
    return W;
}

int kruskal(vector<Edge> &edges){
    int parents[N];
    vector<int> redges;
    for(int i = 0; i < N; i++) parents[i] = i;

    sort(edges.begin(), edges.end(), [](const Edge &A, const Edge &B){
        return A.cost < B.cost;
    });

    int e = 0, u, v, c, W = 0, r = 0;

    while (r < N - 1){
        u = edges[e].src; v = edges[e].tgt; c = edges[e].cost;
        u = find(parents, u); v = find(parents, v);
        if(u != v){
            W += c;
            Union(parents, u, v);
            redges.push_back(e);
            r++;
        }
        e++;
    }

    int w;
    wans = cans = 0;
    for(int i = 0; i < N - 1; i++){
        w = kruskal_(edges, edges[redges[i]].src,  edges[redges[i]].tgt);
        if(W != w){
            cans++;
            wans += edges[redges[i]].cost;
        }
    }
    
    return W;
}

int main() {
    io_boost;
    while(cin >> N >> M){
        vector<Edge> edges;
        for(int i = 0; i < M; i++){
            cin >> U >> V >> C;
            U --; V --;
            edges.push_back(*(new Edge(U, V, C)));
        }
        kruskal(edges);
        cout << cans << " " << wans << endl;
    }
    return 0;
}