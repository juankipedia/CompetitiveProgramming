#include <bits/stdc++.h>
using namespace std;
# define endl "\n"
const int MAXN = 101;
const int INF = std::numeric_limits<int>::max();
int N, T;
int p, q, type; 
vector<pair<int, int>> m[7];
pair<int,int> memo[7][1001];
pair<int, int> zero;

pair<int,int> solve(int t, int type){
	if(type == 0 or t == 0)
		return make_pair(0, INF);
	if(memo[type][t] != zero)
		return memo[type][t];

	int r = 0, minq = 0;
	pair<int,int> maxi;
	for (const auto &p : m[type]){
		if(p.first > t)
			continue;

		maxi = solve(t - p.first, type - 1);
		if(p.second + maxi.first > r){
			r = p.second + maxi.first;
			minq = min(maxi.second, p.second);
		}
	}

	memo[type][t] = make_pair(r, minq);
	return make_pair(r, minq);
}

int main(){
	cin >> N >> T;
	for (int i = 0; i < N; ++i){
		cin >> type >> p >> q;
		m[type].push_back(make_pair(p, q));
	}
	for (int i = 1; i <= 6; ++i){ 
		if(m[i].size() == 0){
			cout << 0 << endl;
			return 0;
		}
	}

	cout << solve(T, 6).second << endl;
    return 0;
}