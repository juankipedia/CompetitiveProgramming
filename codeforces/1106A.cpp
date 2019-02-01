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

int main() {
	io_boost;
	int n;
	cin >> n;
	char m[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> m[i][j];
	
	/*for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << m[i][j];
		}
		cout << endl;
	}*/
	if(n < 3)
		cout << 0 << endl;
	else{
		int r = 0;
		for (int i = 1; i < n - 1; ++i){
			for (int j = 1; j < n - 1; ++j){
				if(m[i][j] == 'X' and m[i][j] == m[i - 1][j - 1] and m[i][j] == m[i-1][j+1] and m[i][j] == m[i+1][j-1] and m[i][j]==m[i+1][j+1])
					r++;
			}
		}
		cout << r << endl;
	}
	
    return 0;
}