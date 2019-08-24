#include <bits/stdc++.h>
using namespace std;

# define endl "\n"

const int MAXN = 1000;
const int MAXM = 300000;
  
int V, m, t, p, a, b ,c;

int minKey(int key[], bool mstSet[]){ 
	int min = INT_MAX, min_index; 
  
	for (int v = 0; v < V; v++) 
	    if (mstSet[v] == false && key[v] < min) 
	        min = key[v], min_index = v; 
  
	return min_index; 
} 
  

int printMST(pair<int, int> parent[], vector<pair<int, int>> graph[]){ 
	int r = 0;
	for (int i = 1; i < V; i++) 
	    r += p * parent[i].second; 
	return r;
} 
int primMST(vector<pair<int, int>> graph[]) { 

    pair<int, int> parent[V];  
    int key[V];  
    bool mstSet[V];  
  
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  

    key[0] = 0;      
    parent[0] = {-1, 0};
  
    for (int count = 0; count < V-1; count++){
        int u = minKey(key, mstSet); 

        mstSet[u] = true; 
  

        for (const auto & v: graph[u]) 
	        if (mstSet[v.first] == false && v.second < key[v.first]) 
	            parent[v.first] = {u, v.second}, key[v.first] = v.second; 
    } 
    return printMST(parent, graph); 
} 
  
  
int main() { 

	cin >> t;
	while(t--){
		cin >> p >> V >> m;
		vector<pair<int, int>> graph[V];
		for (int i = 0; i < m; ++i){
			cin >> a >> b >> c;
			graph[a-1].push_back({b-1, c});
			graph[b-1].push_back({a-1, c});
		}
	    cout << primMST(graph) << endl; 
	}
  
    return 0; 
} 