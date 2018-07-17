# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int t, s_1, s_2;
	string s;
	cin >> t;
	for (unsigned int j = 0; j < t; ++j){
		cin >> s;
		s_2 = s_1 = 0;
		for (unsigned int i = 0; i < s.length(); i = i + 2)
			s_1 +=  static_cast<unsigned int>(s[i]) - static_cast<unsigned int>('0');
		for (unsigned int i = 1; i < s.length(); i = i + 2)
			s_2 +=  static_cast<unsigned int>(s[i]) - static_cast<unsigned int>('0'); 
		if (s_1 < s_2)
			swap(s_1,s_2);
		if(!((s_1 - s_2) % 11) && !((s_1 + s_2) % 9) && (s[s.length() - 1] - static_cast<unsigned int>('0') == 5))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}