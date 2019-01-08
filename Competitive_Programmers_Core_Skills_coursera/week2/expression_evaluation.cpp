# include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	long long int result = 0;
	bool plus = true;
	for (unsigned int i = 0; i < s.length();){
		string num = "";
		while(s[i] != '+' and s[i] != '-' and i < s.length()) {num += s[i], i++;};
		if(plus) result += atoi(num.c_str());
		else result -= atoi(num.c_str());
		if(s[i] == '+') plus = true;
		else plus = false;
		i++;
	}
	cout << result << endl;
	return 0;
} 