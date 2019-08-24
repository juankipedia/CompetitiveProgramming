#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

const int MAX = 50;
int n, m;
int A[MAX][MAX];
int B[MAX][MAX];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> A[i][j];
		}
	}

	vector<pair<int, int> > v;
	for (int i = 0; i < n - 1; ++i){
		for (int j = 0; j < m - 1; ++j){
			if(	

			   A[i][j] == 1 
			   and A[i][j + 1] == 1 and 
			   A[i + 1][j] == 1 and A[i + 1][j + 1] == 1
			   
			   ){
				B[i][j] = 1; 
				B[i][j + 1] = 1;
			    B[i + 1][j] = 1;
			    B[i + 1][j + 1] = 1;
			    v.push_back({i + 1, j + 1});
			}

		}
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(A[i][j] != B[i][j]){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); ++i){
		cout << v[i].first << " " << v[i].second << endl;
	}

    return 0;
}