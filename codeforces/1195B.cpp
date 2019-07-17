#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;

typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

ulli n, k;
ulli pc, r;

int main() {
	cin >> n >> k;

	pc = 1;

	for (ulli i = 2; i <= n; ++i){
		if(pc - (n - i + 1) == k){
			cout << n - i  + 1 << endl;
			return 0;
		}
		pc += i;
	}

	cout << 0 << endl;
    return 0;
}