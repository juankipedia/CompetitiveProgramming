# include <bits/stdc++.h>
using namespace std;

int main(){
	string s, ls;
	cin >> s;
	unsigned int r = 0;
	char c = s[0];
	for (unsigned int i = 1; i < s.length(); ++i){
		if(s[i] != c){
			for (unsigned int i = 0; i < s.length(); ++i){
				string b = ""; b += s[i];

				if(s.find(b, i + 1) == string::npos) continue;
				else if(b.length() > r) r = b.length();

				for (unsigned int j = i + 1; b.length() * 2 <= s.length() - j + 1 and  j < s.length(); ++j){
					b += s[j];
					if(s.find(b, j) == string::npos) break;
					else if(b.length() > r) r = b.length();
				}
			}
			cout << r << endl;
			return 0;
		}
	}
	cout << s.length() - 1 << endl;
}