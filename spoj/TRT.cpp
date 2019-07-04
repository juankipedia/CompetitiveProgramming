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

const int MAXN = 2000;
int N;
lli v[MAXN];

int memo[MAXN][MAXN];
lli solve(int i, int j, int d){

	if(memo[i][j] != 0)
		return memo[i][j];

	if(i >= N)
		return 0;
	if(j < 0)
		return 0;

	if(j == i)
		return d * v[i];

	lli maxi = max(d * v[i] + solve(i + 1, j, d + 1), 
	d * v[j] + solve(i, j - 1, d + 1));
	memo[i][j] = maxi; 
	return maxi;
}


int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> v[i];
	cout << solve(0, N - 1, 1) << endl;
    return 0;
}