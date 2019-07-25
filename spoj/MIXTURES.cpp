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
const int INF = std::numeric_limits<int>::max();
const int MAXN = 100;
int n;
int m[MAXN][MAXN], mix[MAXN];
int tcm[MAXN][MAXN];
int tc;

int cost(int i, int j){
	int r = 0;
	for (int k = i; k <= j; ++k) r += mix[k];

	return r % 100; 
}

int mincost(int i, int j){
	if(i == j)
		return 0;
	if(tcm[i][j] == tc) return m[i][j];
	tcm[i][j] = tc;
	int mini = INF;
	for(int k = i; k < j; k++){
		mini = min(mini, mincost(i, k) + mincost(k + 1, j) + cost(i, k) * cost(k + 1, j));
	}
	m[i][j] = mini;
	return mini;
}

int main() {
	tc = 1;
	while(cin >> n){
		for (int i = 0; i < n; ++i)
			cin >> mix[i];

		cout << mincost(0, n - 1) << endl;
		tc++;
	}

    return 0;
}