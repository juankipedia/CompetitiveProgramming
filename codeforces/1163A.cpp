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
	int n, m;
	cin >> n >> m;
	if(n == m){
		cout << 0 << endl;
		return 0;
	}
	bool c[n] = {false};
	
	for (int i = 0, j = 0; i < m; ++i, j+= 2){
		if(j >= n){
			if(n % 2 != 0)
				j = j % n;
			else
				j =( j % n) + 1;
		}
		//cout << j << endl;
		c[j] = true;

	}

	int count = 0;
	bool counting = false;
	for (int i = 0; i < n; ++i){
		//cout << c[i] << ' ';
		if(c[i] == false and not counting){
			counting = true;
			count ++;
		}

		if(c[i])
			counting = false;

	}

//cout <<endl;

	cout << count << endl;
    return 0;
}