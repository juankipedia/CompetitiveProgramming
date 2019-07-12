#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;

const int MAXM = 1e5;
ulli n, m, k;

ulli p[MAXM];

int main() {
	cin >> n >> m >> k;
	for (ulli i = 0; i < m; ++i) cin >> p[i];

	ulli page = (p[0] - 1) / k, c = 0, ci = 0, op = 0;
	for (ulli i = 0; i < m; ++i){
		if((p[i] - c - 1)/ k == page) ci ++;
		else{
			c += ci;
			page = (p[i] - c - 1)/ k; ci = 1;
			op ++;
		}
	}

	cout << op + 1 << endl;
    return 0;
}