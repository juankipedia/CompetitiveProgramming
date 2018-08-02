# include <bits/stdc++.h>
using namespace std;

bool divisible_by_3(const string &s){
	int r = 0;
	for (unsigned int i = 0; i < s.length(); ++i)
		r += (s[i] - '0');
	if(r % 3)
		return false;
	else
		return true;
}

bool divisible_by_2(char l){
	if((l - '0') % 2)
		return false;
	else
		return true;
}

int main(){
	std::ios::sync_with_stdio(false);
	unsigned int t;
	cin >> t;
	string s;
	while(t--){
		cin >> s;
		if(divisible_by_2(s[s.length() -1]) and divisible_by_3(s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}