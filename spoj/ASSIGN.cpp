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

const int MAXN = 20;
ulli memo[1048578], cmemo[1048578];
int s[MAXN][MAXN], n, c, tc;


ulli numways(int i, int t){
	if(i >= (1 << n) or t >= n)
		return 1;
	if(cmemo[i] == c) return memo[i];
	cmemo[i] = c;
	ulli r = 0;
	for (int j = 0; j < n; ++j){
		if(s[j][t] and !(i & (1 << j))){
			int ni = (i | (1 << j));
			r += numways(ni, t+1);
		}
	}
	memo[i] = r;
	return r;
}

int main() {
	cin >> tc;
	for (c = 1; c <= tc; ++c){
		cin >> n;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				cin >> s[i][j];
			}
		}

		cout << numways(0,0) << endl;
	}	
    return 0;
}