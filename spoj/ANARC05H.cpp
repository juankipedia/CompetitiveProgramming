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

int T;
string s;
int tc, n;

int f(int i, int sum){
	if(i >= n) return 1;

	int r = 0;
	for (int j = 1; i + j <= n; ++j){
		int si = 0;

		for (int k = i; k < j + i and k < n; ++k) si += s[k] - '0';
	
		if(si >= sum) r += f(i + j, si);
	}

	return r;
}

int main() {

	tc = 1;
	while(cin >> s and s != "bye"){
		n = s.length();
		cout << tc << ". " << f(0, 0) << endl;
		tc ++;
	}
    return 0;
}