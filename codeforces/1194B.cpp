#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


int q;
int n, m;


int main() {
	cin >> q;
	while(q --){
		cin >> n >> m;
		std::vector<string> v(n);

		
		int cc[m] = {0};
		int rc[n] = {0};
		for (int i = 0; i < n; ++i){
			cin >> v[i];
			int c = 0;
			for (int j = 0; j < m; ++j){
				if(v[i][j] =='.'){
					rc[i]++;
					cc[j] ++;
				}
			}
		}

		int r = numeric_limits<int>::max();
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if(v[i][j] == '.')
					r = min(rc[i] + cc[j] - 1, r);
				else
					r = min(rc[i] + cc[j], r);
			}
		}

		cout << r << endl;
	}
    return 0;
}