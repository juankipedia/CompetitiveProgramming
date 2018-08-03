# include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	unsigned int t;
	string n;
	cin >> t;
	while(t --){
		cin >> n;
		if(n[n.length() - 1] == '0' or n[n.length() - 1] == '5')
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}