#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int a[n];
	unsigned int neg = 0, pos = 0, z = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] < 0)
			neg ++;
		else if(a[i] > 0)
			pos ++;
		else
			z++;
	}
	int c = (n % 2 == 0) ? (n / 2) : (n/2 + 1);
	if(pos >= c)
		cout << 1 << endl;
	else if(neg >= c)
		cout << -1 << endl;
	else cout << 0 << endl;

    return 0;
}