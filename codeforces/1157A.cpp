#include <bits/stdc++.h>
using namespace std;

unsigned int f(unsigned int n){
	n = n + 1;
	string n_s = to_string(n);
	if(n_s[n_s.length() - 1] == '0'){
		int i = n_s.length() - 1;
		while(n_s[i] == '0') i--;
		n_s = n_s.substr(0, i + 1);
		return atoll(n_s.c_str());
	}
	else
		return n;
}

int main() {
	unsigned int n;
	cin >> n;
	unordered_set<unsigned int> m;
	while(m.find(n) == m.end()){
		m.insert(n);
		n = f(n);
	}

	cout << m.size() << endl;
    return 0;
}