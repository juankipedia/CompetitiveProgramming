#include <bits/stdc++.h>
using namespace std;
struct Stree{
	int n;
	vector<int> tree;
	Stree (int n) : n(n) {
		tree.assign(2*n+100,0);
	}
	void update(int k, int x){
		k += n;
		tree[k] = x;
		for(k>>=1; k; k>>=1) tree[k] = max(tree[k<<1],tree[(k<<1)|1]);
	}
	int query(int l, int r){
		int ans = 0;
		l += n, r+=n;
		while(l<=r){
			if(l&1) ans = max(ans,tree[l++]);
			if(!(r&1)) ans = max(ans,tree[r--]);
			l>>=1,r>>=1;
		}
		return ans;
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long w;
	cin>>n>>w;
	Stree st(2*n+1000);
	for(int i=0; i<n; i++){
		int x; cin>>x;
		st.update(i,x);
	}
	int ans = 1e6;
	for(int i=1; i<=n; i++){
		long long cur = 0;
		for(int j=0; j<n; j+=i){
			cur += 1ll*st.query(j,j+i-1)+1ll;
		}
		cur--;
		if(cur <= 1ll*w)ans = min(ans,i);
	}
	cout<<ans<<'\n';
	return 0;
}