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

const int MAXN = 31;
int n, tc;
int a[MAXN][3];

int memo[2502][2502];
int memo_tc[2502][2502];

int f(int w, int h){
	if(memo_tc[w][h] == tc) return memo[w][h];
	memo_tc[w][h] = tc;
	int maxi = 0;
	for (int i = 0; i < n; ++i){
		if(a[i][0] < w and a[i][1] < h)
			maxi = max(maxi, a[i][2] + f(a[i][0], a[i][1]));
		if(a[i][0] < h and a[i][1] < w)
			maxi = max(maxi, a[i][2] + f(a[i][1], a[i][0]));
		if(a[i][0] < w and a[i][2] < h)
			maxi = max(maxi, a[i][1] + f(a[i][0], a[i][2]));
		if(a[i][0] < h and a[i][2] < w)
			maxi = max(maxi, a[i][1] + f(a[i][2], a[i][0]));
		if(a[i][1] < w and a[i][2] < h)
			maxi = max(maxi, a[i][0] + f(a[i][1], a[i][2]));
		if(a[i][1] < h and a[i][2] < w)
			maxi = max(maxi, a[i][0] + f(a[i][2], a[i][1]));
			
	}

	memo[w][h] = maxi;
	return maxi;
}

int main() {
	tc = 1;
	while(cin >> n and n != 0){
		for (int i = 0; i < n; ++i)
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		cout << f(2501, 2501) << endl;
		tc++;
	}
    return 0;
}