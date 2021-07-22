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
const ll mod = 1e9 + 7;
ll add(ll a, ll b) { a %= mod, b %= mod; return a + b >= mod ? a + b - mod: a + b; }
ll sub(ll a, ll b) { a %= mod, b %= mod; return a >= b ? a - b : a - b + mod; }
ll mul(ll a, ll b) { a %= mod; b %= mod; return a * b % mod; }
ll powmod(ll b, ll e) {
	ll ans = 1;
	for (ll m = b; e; e >>= 1, m = mul(m, m)) if (e & 1) ans = mul(ans, m);
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, c; cin >> n >> m >> c;
	ll d = powmod(c, n * n);
    ll s = 0;
    
    for(int i = 1; i <= m; i++) s = add(s, powmod(d, __gcd(i, m)));
    
    cout << mul(s, powmod(m, mod - 2)) << endl;
	return 0;
}