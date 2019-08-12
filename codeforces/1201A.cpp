#include <bits/stdc++.h>
using namespace std;

# define endl "\n"

const int MAXN = 1000;
int n, m;
std::vector<string> a(MAXN);

int memo[5][MAXN];
int p[MAXN];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i){
		cin >> p[i];
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			memo[a[i][j] - 'A'][j]++;
		}
	}

	int r=0;
	for (int i = 0; i < m; ++i){
		int maxi = 0;
		for (int j = 0; j < 5; ++j){
			maxi = max(maxi, memo[j][i]);
		}

		r += maxi * p[i];
	}

	cout << r << endl;
    return 0;
}