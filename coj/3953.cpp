# include <bits/stdc++.h>
using namespace std;

string beautiful_string(string s, unsigned int k){
	if(k > s.length())
		return "";
	unordered_map<char, bool> m;
	string sk = "";
	sk += s[0];
	m[s[0]] = true;
	k --;
	for (unsigned int i = 1; i < s.length(); ++i){
		if(s[i] != sk[0] and m.find(s[i]) == m.end() and k > 0){
			m[s[i]] = true;
			sk = "";
			sk += s[i];
			k --;
		}
		else
			sk += s[i];
	}
	if(k > 0)
		return "";
	return sk;
}

int main(){
	unsigned int k;
	string s;
	cin >> k;
	cin >> s;
	s = beautiful_string(s, k);
	if(s == "")
		cout << "NO" << endl;
	else
		cout << "YES\n" << s << endl;
	return 0;
}