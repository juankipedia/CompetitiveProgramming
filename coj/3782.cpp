# include <bits/stdc++.h>
using namespace std;

int main(){
	long long unsigned int t;
	cin >> t;
	while(t--){
		unsigned short a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		if(a + 1 == b and b + 1 == c and c + 1 == d and d + 1 == e)
			cout << 'Y' << endl;
		else
			cout << 'N' << endl;
	}
	return 0;
}