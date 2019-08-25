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

const int MAXV = 1000000;
const ulli INF = 1000000000;
int V, E;
 
ulli shortest_path(int src, vector<pair<int, ulli>> g[]) { 
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq; 
    vector<ulli> dist(V, INF); 
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

    ulli r = 0;
    for (const ulli &d : dist ){
    	if(d != INF){
    		//cout << d << endl;
    		r+=d;
    	}
    }

    return r;
} 


int main() {
	int t;
	cin >> t;
	while(t--){
		int a, b;
		ulli p;
		cin >> V >> E;
		vector<pair<int, ulli>> G[V], G_[V];
		for (int i = 0; i < E; ++i){
			cin >> a >> b >> p;
			G[a - 1].push_back({b - 1, p});
			G_[b - 1].push_back({a - 1, p});
		}

		cout << shortest_path(0, G) + shortest_path(0, G_) << endl;
    }
    return 0;
}