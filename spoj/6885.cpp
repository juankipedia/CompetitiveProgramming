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

const int INF = 1001;

int P, T, p1, p2, l;


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
	while(cin >> P >> T){

		vector<pair<int, int>>  g[P];
		vector<int> dist0(P, INF);
		vector<int> distHp(P, INF);
		vector<pair< pair<int, int>, int> > t;

		while(T--){
			cin >> p1 >> p2 >> l;
			g[p1].push_back({p2, l});
			g[p2].push_back({p1, l});
			t.push_back({{p1, p2}, l});
		}

		shortest_path(0, g, dist0);
		shortest_path(P - 1, g, distHp);

		int r = 0;
		for(const auto &e: t){
			if(dist0[e.first.first] + e.second + distHp[e.first.second] == dist0[P - 1] or
			   dist0[e.first.second] + e.second + distHp[e.first.first] == dist0[P - 1] )
				r += e.second;
		}

		cout << r * 2 << endl;
	}
    return 0;
}