#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
 
struct STree {
	struct Node {
		ll val, sum, l, r;
	};
	int n;
	vector <bool> marked;
	vector <Node> tree;
	STree (int n) : n(n) {
		tree.resize((n << 2));
		marked.assign((n << 2), 0);
	}
	void build(int u, int tl, int tr, vector <pii> &a) {
		if (tl == tr) {
			tree[u].r = a[tl].second, tree[u].l = a[tl].first;
			tree[u].sum = tree[u].r - tree[u].l;
			tree[u].val = 1;
		} else {
			int tm = (tl + tr) >> 1;
			build(u << 1, tl, tm, a); build(u << 1 | 1, tm + 1, tr, a);
			tree[u].l = tree[u << 1].l, tree[u].r = tree[u << 1 | 1].r;
			tree[u].sum = tree[u].r - tree[u].l;
			tree[u].val = 1;
		}
	}
	void push(int u) {
		if (marked[u]) {
			tree[u << 1].val = tree[u << 1 | 1].val = tree[u].val;
			tree[u].sum = tree[u].val * (tree[u].r - tree[u].l);
			tree[u << 1].sum = tree[u << 1].val * (tree[u << 1].r - tree[u << 1].l);
			tree[u << 1 | 1].sum = tree[u << 1 | 1].val * (tree[u << 1 | 1].r - tree[u << 1 | 1].l);
			marked[u << 1] = marked[u << 1 | 1] = 1;
			marked[u] = 0;
		}
	}
	void update(int u, int tl, int tr, int l, int r, ll val) {
		if (l > r) return;
		if (tl == l && tr == r) {
			tree[u].val = val;
			tree[u].sum = val * (tree[u].r - tree[u].l);
			marked[u] = 1;
		} else {
			push(u);
			int tm = (tr + tl) >> 1;
			update(u << 1, tl, tm, l, min(tm, r), val);
			update(u << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
			tree[u].sum = tree[u << 1].sum + tree[u << 1 | 1].sum;
		}
	}
	ll query() { return tree[1].sum; }
};
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n; int m; cin >> n >> m;
	vector <tuple<ll, ll, int>> q;
	vector <ll> c = {0, n};
	for (int i = 0; i < m; ++i) {
		ll l, r; int qi; cin >> l >> r >> qi;
		c.push_back(l);
		c.push_back(l - 1);
		c.push_back(r);
		q.push_back({l, r, qi - 1});
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	vector <pii> a = {{0, 0}}; //Dummy value
	for (int i = 1; i < c.size(); ++i) a.push_back({c[i - 1], c[i]});
	int sz = a.size();
	STree st(sz);
	st.build(1, 0, sz - 1, a);
	vector <int> l(m),r(m);
	for (int i = 0; i < m; ++i) {
		ll li, ri; int qi; tie(li, ri, qi) = q[i];
		l[i] = lower_bound(c.begin(), c.end(), li) - c.begin();
		r[i] = lower_bound(c.begin(), c.end(), ri) - c.begin();
	}
	for (int i = 0; i < m; ++i) {
		int qi = get<2>(q[i]);
		st.update(1, 0, sz - 1, l[i], r[i], qi & 1);
		cout << st.query() << endl;
	}
	return 0;
}
