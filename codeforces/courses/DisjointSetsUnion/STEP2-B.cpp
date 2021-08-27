# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/
 
struct DSU {
	int n, comp = n;
	vector<int> p, len, maxi;
	DSU(int n) : n(n){
		p.assign(n + 10, 0); 
        iota(p.begin(), p.end(), 0);
		len.assign(n + 10, 1);
        maxi = p;
	}
	int find(int n){ return p[n] = p[n] == n ? n : find(p[n]); }
	void join(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		maxi[a] = max(maxi[b], maxi[a]);
        len[a] += len[b];
		p[b] = a;
		comp--;
	}
};
 
int n;
 
int main(){
    io_boost;
    cin >> n;
    DSU d(2 * n);
    int ans[n];
    for(int i = 0, u; i < n; i++){
        cin >> u;
        u--;
        u = d.find(u);
        ans[i] = u + 1;
        if((u + 1) != n) d.join(u + 1, u);
        else d.join(0, u);
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}