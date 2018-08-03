# include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	unsigned int t;
	string n;
	size_t sum = 0;
	cin >> t;
	while(t --){
		sum = 0;
		cin >> n;
		for (unsigned int i = (n[0] == '-') ? (1) : (0); i < n.length(); ++i)
			sum += n[i] - '0';
		cout << sum << endl;
	}
	return 0;
}