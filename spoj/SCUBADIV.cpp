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

const int MAXT = 22, MAXA = 80, MAXN = 1001, INF = std::numeric_limits<int>::max();
int c, t, a, n, w, C;

tuple<int, int, int> cs[MAXN];

lli s[MAXN][MAXT][MAXA], tc[MAXN][MAXT][MAXA];

lli solve(int ti, int ai, int ni){
	if(ti <= 0 and ai <= 0)
		return 0;
	
	if(ni == 0)
		return INF;

	ti  = ti <= 0 ? 0 : ti;
	ai  = ai <= 0 ? 0 : ai;

	if(tc[ni][ti][ai] == c)
		return s[ni][ti][ai];

	tc[ni][ti][ai] = c;

	lli mini = min(
		get<2>(cs[ni - 1]) + solve(ti - get<0>(cs[ni - 1]), ai - get<1>(cs[ni - 1]), ni - 1),	
		solve(ti, ai, ni - 1)
	);
	
	s[ni][ti][ai] = mini;
	return mini;
}

int main() {
	cin >> C;
	for (c = 1; c <= C; ++c){
		cin >> t >> a;
		cin >> n;
		for (int i = 0; i < n; ++i) 
			cin >> get<0>(cs[i]) >> get<1>(cs[i]) >> get<2>(cs[i]);
	
		cout << solve(t, a, n) << endl;
	}
    return 0;
}