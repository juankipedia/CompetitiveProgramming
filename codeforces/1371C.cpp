#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli a, b, n, m;

int main(){
    cin >> t;
    while (t--) {
		lli a, b, n, m;
		cin >> a >> b >> n >> m;
		int flag = 0;
		if (a > b) {
			if (b >= m) b -= m;
			else flag = 1;
		}
		else {
			if (a >= m) a -= m;
			else flag = 1;
		}
		if (flag) {
			cout << "No\n";
			continue;
		}
		if (a + b >= n) cout << "Yes\n";
		else cout << "No\n";
	}
    return 0;
}