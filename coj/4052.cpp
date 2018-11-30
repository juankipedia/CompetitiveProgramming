# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int t;
	cin >> t;
	string c;
	while(t--){
		cin >> c;
		string b;
		for (unsigned int i = 0; i < c.length() - 1; i += 2)
			b+= string(c[i] - '0', c[i + 1]);
		cout << b << endl;
	}	
	return 0;
}