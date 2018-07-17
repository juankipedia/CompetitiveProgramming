# include <bits/stdc++.h>

using namespace std;
int main(){
	unsigned int t;
	cin >> t;
	for (unsigned int i = 0; i < t; ++i){
		double l;
		cin >> l;
		double a = (l * l) - (M_PI * l / 2 * l / 2); 
		cout << setprecision(2) << fixed << a << "\n";
	}
	return 0;
}