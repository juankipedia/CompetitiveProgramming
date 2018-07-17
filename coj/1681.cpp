# include <bits/stdc++.h>
using namespace std;

int main(){
	double a,b,c;
	cin >> a;
	cin >> b;
	cin >> c;

	if(b * b - 4 * a * c >= 0)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}