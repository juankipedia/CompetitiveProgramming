#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;

const int MAXN = 1001;
int n;
int a[2 * MAXN];
int main() {
	cin >> n;
	for (int i = 0; i < 2 * n; ++i) cin >> a[i];
	sort(a, a+ (2 * n));
	ulli f = 0;
	ulli s = 0;
	for (int i = 0; i < n; ++i){
		f += a[i];
	}

	for (int i = n; i < 2 * n; ++i){
		s += a[i];
	}

	if(s != f){
		for (int i = 0; i < 2 * n; ++i)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
	else{
		cout << -1 << endl;
	}
    return 0;
}