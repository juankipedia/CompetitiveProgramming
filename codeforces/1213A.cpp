#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;


const int MAXN = 100;
lli x[MAXN];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> x[i];

	lli min_c = std::numeric_limits<lli>::max();
	for (int i = 0; i < n; ++i){
		lli ci = 0;
		for (int j = 0; j < n; ++j){
			if(j != i){
				lli a = abs(x[j] - x[i]);
				lli pm = a / 2;
				a -= pm * 2;
				ci += a;
			}
		}
		min_c = min(min_c, ci);
	}

	cout << min_c << endl;

    return 0;
}