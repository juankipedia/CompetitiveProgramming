# include <bits/stdc++.h>
using namespace std;

void count_opt(size_t p, string  & s, size_t n, unordered_map<size_t, size_t> & m){
	
	if(p == n - 1){
		if(s[p] == '0')
			m[p] = 0;
		else
			m[p] = 1;
		return;
	}
	
	count_opt(p + 1, s, n, m);

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
	return;
}

int main (){
	
	string s;
	
	while(cin >> s){
		if(s == "0")
			break;
		unordered_map<size_t, size_t> m;
		m[s.length()] = 1;
		count_opt(0, s, s.length(), m);
		cout << m[0] << endl;
	}
	return 0;
}