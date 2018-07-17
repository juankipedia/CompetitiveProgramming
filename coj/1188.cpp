# include <bits/stdc++.h>
using namespace std;
int main(){
	string f, s;
	cin >> f;
	cin >> s;
	size_t n = 0;
	for (unsigned int i = 0; i < f.length() ; ++i){
		for (unsigned int j = 0; j < s.length() ; ++j){
			n += static_cast<size_t>(f[i] - '0') * static_cast<size_t>(s[j] - '0');
		}	
	}
	cout << n << "\n";
	return 0;
}