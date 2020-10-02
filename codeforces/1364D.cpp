#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<lli, int> pair_l;
const int oo = numeric_limits<int>::max();

struct cyc{int a, b, l; };

int n, m, k, c=-1;
vector<int> G[200001];
int parent[200001], h[200001];
cyc cycle;
 
void dfs(int v, int p){
	parent[v] = p;
	h[v] = h[p]+1;
	for(int w: G[v]) if(w!=p){
		if(!parent[w]) dfs(w,v);
		else{
			c = abs(h[w]-h[v])+1;
			if( c<cycle.l ){
				cycle.a = v, cycle.b = w, cycle.l = c;
			}
		}
	} 
}
 
vector<int> biColor(){
	vector<int> s1, s2;
	int need = k/2.0+0.99999999, v;
 
	for(int v=1; v<=n && s1.size()<need && s2.size()<need ; v++){
		if( h[v]%2==1 ) s1.push_back(v);
		else s2.push_back(v);
	}
 
	if( s1.size()==need ) return s1;
	else return s2;
}
 
int main() {
	cin >> n >> m >> k; 
    int v, w, need;
    for(int i = 0; i < m; i++){
        cin >> v >> w; G[v].push_back(w); G[w].push_back(v);
    }
	
	cycle.l = oo;
	dfs(1,1);
 
	vector<int> ans;
	if( cycle.l==oo ){
		printf("1\n");
		ans = biColor();
		for(int v: ans) printf("%d ", v);
		printf("\n");
	}else{
		if( cycle.l <= k ){
			printf("2\n%d\n",cycle.l);
			v = cycle.a; w = cycle.b;
			while( v != w ) printf("%d ", v), v = parent[v];
			printf("%d\n", w);
		}else{
			v = cycle.a; need = k/2.0+0.9999999;
			while( ans.size()<need ) ans.push_back(v), v = parent[ parent[v] ];
			printf("1\n");
			for(int v: ans) printf("%d ", v);
			printf("\n");
		}
	}
}