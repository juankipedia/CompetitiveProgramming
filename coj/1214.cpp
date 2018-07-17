# include <bits/stdc++.h>

using namespace std;

int main(){
	unsigned int t;
	double a,s;

	cin >> t;

	for (unsigned int i = 0; i < t; ++i){
		cin >> a >> s;
		cout << setprecision(2) << fixed << sqrt(s * s - 4 * a) / 2 << "\n";
	}
	return 0;
}