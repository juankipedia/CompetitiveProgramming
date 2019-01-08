# include <bits/stdc++.h>
using namespace std;
typedef long long unsigned int ui;

int main(){
	ui n;
	cin >> n;
	ui a[n], r = 0;
	for (ui i = 0; i < n; ++i){cin >> a[i]; r += a[i];};
	for (ui i = 2; i <= n; ++i){
		for (ui j = 0; j <= n - i; ++j){
			ui min = a[j];
			for (ui k = 1; k < i; ++k) if(a[j + k] < min) min = a[j + k];
			r += min;
		}
	}
	cout << r << endl;
	return 0;
} 