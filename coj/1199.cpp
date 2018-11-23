# include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ui;


ui f(ui t[], const ui &l, const ui &r, bool left){
	if(l > r){
		if(left)
			return 1;
		else
			return 0;
	}
	ui i;
	for (i = l; i <= r; ++i)
		if(t[i] > t[l])
			break;
	return t[l] * f(t, l + 1, i - 1, true) + f(t, i, r, false);
}

int main(){
	ui k, n;
	cin >> k;
	while(k --){
		cin >> n;
		ui t[n];
		for (ui i = 0; i < n; ++i){
			cin >> t[i];
		}

		cout << f(t, 0, n - 1, true) << endl;
	}
	return 0;
}