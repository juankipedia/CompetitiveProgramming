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

int T, E, F, N;

pair<int, int> pw[500];

lli minp_(int W, unordered_map<int, lli> &m){
	if(m.find(W) != m.end())
		return m[W];
	if(W == 0)
		return 0;
	if(W < 0)
		return -1;

	lli r = numeric_limits<lli>::max(), mini;
	for (int i = 0; i < N; ++i){
		lli v = minp_(W - pw[i].second, m);
		
		if(v == -1) continue;
		else mini = pw[i].first + v;

		if(mini < r)
			r = mini;
	}

	if(r == numeric_limits<lli>::max()){
		m[W] = -1;
		return -1;
	}
	else m[W] = r;
	return r;
}


lli minp(int W){
	unordered_map<int, lli> m;
	minp_(W, m);
	return m[W];
}

int main() {
	cin >> T;
	while(T--){
		cin >> E >> F;
		cin >> N;
		for (int i = 0; i < N; ++i) cin >> pw[i].first >> pw[i].second;

		if(E == F){
			cout << "The minimum amount of money in the piggy-bank is " << 0 << '.' << endl;
			continue;
		}
		lli r = minp(F - E);
		if(r == -1)
			cout << "This is impossible." << endl;
		else cout << "The minimum amount of money in the piggy-bank is " << r << '.' << endl;
	}
    return 0;
}