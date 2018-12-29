#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int ulli;
typedef long long int lli;
typedef unsigned int ui;

int main() {
	ui n;
	cin >> n;
	ui a[n];
	for (ui i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	if(a[n - 1] - a[1] < a[n - 2] - a[0])
		cout << a[n - 1] - a[1] << endl;
	else cout << a[n - 2] - a[0] << endl;
    return 0;
}