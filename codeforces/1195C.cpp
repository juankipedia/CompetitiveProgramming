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

const int MAXN = 1e5;
int n;
ulli r1[MAXN];
ulli r2[MAXN];
ulli memo[MAXN][2];

ulli f(int i, int r){
	if(i >= n)
		return 0;

	if(memo[i][r] != 0) return memo[i][r];

	ulli maxi = 0;
	if(r == 0){
		maxi = max(r2[i] + f(i +1, 1), r2[i] + f(i + 2, 1));
	}
	else{
		maxi = max(r1[i] + f(i +1, 0), r1[i] + f(i + 2, 0));
	}

	memo[i][r] = maxi;
	return maxi;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> r1[i];
	for (int i = 0; i < n; ++i) cin >> r2[i];

	cout << max(f(0, 0), f(0, 1)) << endl;
    return 0;
}