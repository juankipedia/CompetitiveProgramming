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
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	ui c = std::numeric_limits<ui>::max(),t = a[0];
	for (int t_i = a[0]; t_i <= a[n - 1]; ++t_i){

		ui c_i = 0;
		for (int i = 0; i < n; ++i){
			if(a[i] == t_i)
				continue;
			else if(a[i] > t_i)
				c_i += abs(a[i] - (t_i + 1));
			else
				c_i += abs(a[i] - (t_i - 1));
		}

				//cout << t_i  << " " << c_i<< endl;
		if(c > c_i){
			c = c_i;
			t = t_i;
		}
	}

	cout << t << " " << c << endl; 
    return 0;
}