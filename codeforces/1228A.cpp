#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int l, r;

int main() {
	cin >> l >> r;

	for (int i = l; i <= r; ++i){
		string s = to_string(i);
		bool m[10] = {false};
		bool f= true;
		for (const char &c: s){
			if(m[c - '0'] == true){
				f = false;
				break;
			}
			else m[c - '0'] = true;
		}
		if(f){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
    return 0;
}