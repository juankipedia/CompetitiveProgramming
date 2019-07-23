#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
const int maxn = 1e5;

int t, n;
int a[maxn];

int main() {
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n, std::greater<int>());
		int b1 = a[0], b2= a[1];
		int maxk = min(b1, b2);
if(n - 2 >= maxk - 1){
			cout << maxk - 1 << endl;
		}
		else{
			cout << n - 2 << endl;
		}

	}
    return 0;
}