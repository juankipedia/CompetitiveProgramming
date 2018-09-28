# include <bits/stdc++.h>
using namespace std;

void count(string s, size_t n, unsigned int m []){
	m[n] = 1;
	if(s[n - 1] == '0')
		m[n - 1] = 0;
	else
		m[n - 1] = 1;
	
	for (int p = n - 1; p >= 0; p--){
		if(p + 1 != n and (s[p] == '1' or s[p] == '2' and s[p + 1] <= '6')){
			if(p + 2 != n and s[p + 2] == '0')
				m[p] = m[p + 1];
			else if(s[p + 1] == '0')
				m[p] = m[p + 2];
			else
				m[p] = m[p + 1] + m[p + 2];
		}
		else
			m[p] = m[p + 1];
	}
}

int main (){
	size_t n;
	string s;
	
	while(cin >> s){
		if(s == "0")
			break;
		n = s.length();
		unsigned int m[n + 1];
		count(s, n, m);
		cout << m[0] << endl;
	}
	return 0;
}