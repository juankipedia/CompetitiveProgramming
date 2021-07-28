#include <bits/stdc++.h>
using namespace std;
/* * * *   * * *   	* * * */
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
/* * * *   * * *   	* * * */
/* *
 *
 * Too many mind, no mind.
 *
 * */
const ll oo = 1e15;
const int maxn = 301, maxm = 2001;
ll a[maxn], c[maxn];
ll dp[maxn][maxm];
int n, k;
vector <ll> p;
vector <ll> dec(int x) {
	vector <ll> ans;
	for (ll i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			ans.push_back(i);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) ans.push_back(x);
	return ans;
}
ll go(int i, int mask) {
	if (i >= n) return mask != (1 << p.size()) - 1 ? oo : 0;
	ll &ans = dp[i][mask];
	if (ans != -1) return ans;
	ans = oo;
	//inc
	int aux = 0;
	for (int j = 0; j < p.size(); ++j) if (a[i] % p[j]) aux += (1 << j);
	ans = min(ans, go(i + 1, mask | aux) + c[i]);
	//not inc
	if (i != k) ans = min(ans, go(i + 1, mask));
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> c[i];
	ll ans = oo;
	for (int i = 0; i < n; ++i) {
		p = dec(a[i]);
		memset(dp, -1, sizeof dp);
		k = i;
		ans = min(ans, go(0, 0));
	}
	cout << (ans >= oo ? -1 : ans) << '\n';
	return 0;
}
