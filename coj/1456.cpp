# include <bits/stdc++.h>
using namespace std;



int main(){
	long long unsigned int n;
	cin >> n;
	unordered_map<string, unsigned int> m;
	while(n--){
		string s;
		cin >> s;
		m[move(s)]++;
	}
	for(const auto &n: m)
		if(n.second == 1)
			cout << n.first << endl;
	return 0;
}