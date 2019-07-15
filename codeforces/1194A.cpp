#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;


int t;
lli n, x;

int main() {
	cin >> t;
	while(t--){
		cin >> n >> x;
		int r = 0;
		for (int i = 0; i < x; ++i){
			r += 2;
		}
		cout << r << endl;
	}
    return 0;
}