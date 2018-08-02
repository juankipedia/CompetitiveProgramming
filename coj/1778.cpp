# include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	unsigned int t, a, b;
	cin >> t;
	while(t --){
		cin >> a >> b;
		long double mn = a / 2.0l;
		long double cn = b / 2.0l;
		cout << setprecision(8) << fixed << (mn * cn / 2) + (mn * cn / 4) << endl; 

	}
	return 0;
}