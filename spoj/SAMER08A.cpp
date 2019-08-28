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

const int INF = std::numeric_limits<int>::max();

int N, M, S, D, U, V, P;


void shortest_path(int src, vector<pair<int, int>> g[], vector<int> &dist) { 
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq; 

    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()){ 
        int u = pq.top().second; 
        pq.pop(); 
        for (auto i = g[u].begin(); i != g[u].end(); ++i){ 
            int v = (*i).first; 
            int weight = (*i).second; 
 
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
}

int main() {
	while(cin >> N >> M and N != 0 and M != 0){
		cin >> S >> D;
		vector<pair<int, int>>  g[N], g_[N], p[N];
		vector<int>dist(N, INF), dist_t(N, INF), r_dist(N, INF);
		while(M--){
			cin >> U >> V >> P;
			g[U].push_back({V, P});
			g_[V].push_back({U, P});
		}

		shortest_path(S, g, dist);
		shortest_path(D, g_, dist_t);
		int bd = dist[D];
		if(bd == INF){
			cout << -1 << endl;
			continue;
		}

		for (int i = 0; i < N; ++i){
			for(const auto &e: g[i]){
				if(dist[i] + e.second + dist_t[e.first] != bd)
					p[i].push_back(e);
			}
		}

		shortest_path(S, p, r_dist);

		if(r_dist[D] != INF) cout << r_dist[D] << endl;
		else cout << -1 << endl;
	}
    return 0;
}