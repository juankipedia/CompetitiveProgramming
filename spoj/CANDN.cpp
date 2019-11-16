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

const ulli INF = std::numeric_limits<ulli>::max();
ulli J, B, C, N, S, E1, E2, L;

void shortest_path(ulli src, vector<pair<ulli, ulli>> g[], vector<ulli> &dist) { 
    priority_queue< pair<ulli,ulli>, vector <pair<ulli,ulli>> , greater<pair<ulli,ulli>> > pq; 

    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()){ 
        ulli u = pq.top().second; 
        pq.pop(); 
        for (auto i = g[u].begin(); i != g[u].end(); ++i){ 
            ulli v = (*i).first; 
            ulli weight = (*i).second; 
 
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
}


int main() {
	io_boost;
	while(cin >> J >> B >> C >> N >> S and J != -1 and B != -1 and C != -1 and N != -1 and S != -1){
		vector<pair<ulli, ulli>> g[J];
		vector<ulli> x_n(J, INF), x_c(J, INF), b_x(J, INF);
		vector<pair<pair<ulli, ulli>, ulli>> edges;
		for (ulli i = 0; i < S; ++i){
			cin >> E1 >> E2 >> L;
			g[E1 - 1].push_back({E2 - 1, L});
			g[E2 - 1].push_back({E1 - 1, L});
			edges.push_back({{E1 - 1,E2 - 1}, L});
		}

		shortest_path(C - 1, g, x_c);
		shortest_path(N - 1, g, x_n);
		shortest_path(B - 1, g, b_x);
		
		ulli t = 0;

		for (int i = 0; i < J; ++i){
			if(b_x[i] + x_c[i] == b_x[C - 1] and b_x[i] + x_n[i] == b_x[N - 1])
				t = max(b_x[i], t);
		}

		cout << t << " " << x_c[B -1] - t << " " << x_n[B -1] - t << " " << endl;
	}
    return 0;
}