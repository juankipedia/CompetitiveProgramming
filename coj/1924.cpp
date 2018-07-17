# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int t;
	cin >> t;
	for (unsigned int i = 0; i < t; ++i){
		size_t r;
		cin >> r;
		double a = r * 1.73205080756887729352744634 / 2  *  r;
		double f = r * 1.73205080756887729352744634;
		double s = (2 * r + f + r) / 2; 
		cout << setprecision(1) << fixed << (a / s) * 2 << "\n";
	}
	return 0;
}