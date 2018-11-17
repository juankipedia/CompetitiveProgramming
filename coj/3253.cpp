# include <bits/stdc++.h>
using namespace std;



int main(){
	size_t n, c, ai;
	cin >> n;
	unordered_map<size_t, bool> m;
	while(n --){
		cin >> c;
		while (c --){
			cin >> ai;
			m[ai] = true;
		}
	}
	cout << m.size() << endl;
	return 0;
}