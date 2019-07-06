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

const int MAXH = 100, MAXW = 100;
int T, h, w;
int m[MAXH][MAXW];
int memo[MAXH][MAXW];
int max_path_(int i, int j){
	if(i < 0)
		return 0;
	if(i >= h)
		return 0;
	if(j < 0)
		return 0;
	if(j >= w)
		return 0;
	if(memo[i][j] != -1)
		return memo[i][j];
	int maxi = max(
		m[i][j] + max_path_(i + 1, j + 1), m[i][j] + max_path_(i + 1, j - 1));

	maxi = max(maxi, m[i][j] + max_path_(i + 1, j));

	memo[i][j] = maxi;
	return maxi;
}

int max_path(){
	int maxi = 0;
	for (int i = 0; i < w; ++i) maxi = max(maxi, max_path_(0,i));
	return maxi;
}

int main() {
	cin >> T;
	while(T--){
		cin >> h >> w;
		for (int i = 0; i < h; ++i){
			for (int j = 0; j < w; ++j){
				cin >> m[i][j];
				memo[i][j] = -1;
			}
		}

		cout << max_path() << endl;
	}
    return 0;
}