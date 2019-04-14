#include <bits/stdc++.h>
using namespace std;

# define endl "\n"

typedef vector<int> vector_i;

int main() {
	int n, m, h;
	cin >> n >> m >> h;
	int f[m], l[n], r[n][m], a;
	for (int i = 0; i < m; ++i) cin >> f[i];
	for (int i = 0; i < n; ++i) cin >> l[i];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> a;
			if(a) r[i][j] = min(f[j], l[i]);
			else r[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cout << r[i][j] << " ";
		}
		cout << endl;
	}

    return 0;
}