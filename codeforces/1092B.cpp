#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int main() {
	ui n;
	cin >> n;
	ui a[n];
	for (ui i = 0; i < n; ++i)
		cin >> a[i];

	sort(a , a + n);
	ui c = 0;
	for (ui i = 0; i < n; i += 2) c += a[i + 1] - a[i]; 
	cout << c << endl;
    return 0;
}