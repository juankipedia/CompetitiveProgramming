# include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	size_t n = 0;
	cin >> s;
	for (int i = 0; i < s.length(); ++i){
		n += static_cast<size_t>(s[i]) - static_cast<size_t>('A') + 1;
	}
	cout << n << "\n";
	return 0;
}