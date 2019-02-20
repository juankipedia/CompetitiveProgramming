#include <bits/stdc++.h>
using namespace std;

# define endl "\n"

int main() {
	unsigned long long int q, n, a, b;
	cin >> q;
	while(q--){
		cin >> n >> a >> b;
		unsigned long long int r  = n - (n / 2) * 2;
		unsigned long long int r_a = (n / 2) * b;
		if(r != 0)
			r_a += r * a;
		unsigned long long int r_b = n * a;
		if(r_a < r_b) cout << r_a << endl;
		else cout << r_b << endl;
	}
    return 0;
}