#include <bits/stdc++.h>
using namespace std;

# define endl "\n"

int main() {
	int n;
	cin >> n;
	int a, m = 0, r = 0;
	for (int i = 1; i <= n; ++i){
		cin >> a;
		if(a > m)
			m = a;
		if(m == i){
			r++;
			m = 0;
		}
	}

	cout << r << endl;
    return 0;
}