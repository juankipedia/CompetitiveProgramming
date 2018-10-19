# include <bits/stdc++.h>
using namespace std;

size_t m = 1000003;

map<pair<size_t, size_t>, size_t> c_m;
map<int, size_t> obn_m;

size_t comb(int n, int r){
	if(r == 0 or n == r)
		return 1;	
	else if(n == 0)
		return 0;

	map<pair<size_t, size_t>, size_t>::iterator it = c_m.find(make_pair(n, r));
	if(it != c_m.end())
		return it->second;

	size_t res = (comb(n - 1, r - 1) + comb(n - 1, r)) % m;
	c_m[make_pair(n, r)] = res;
	return res;
}

size_t ordered_bell_number(int n){
	if(n == 0 or n == 1) return 1;
	else if(n == 2) return 3;
	else if(n == 3) return 13;

	map<int, size_t>::iterator it = obn_m.find(n);
	if(it != obn_m.end())
		return it->second;

	size_t res = 0;
	for (int i = 1; i <= n; ++i) res = (res + comb(n, i) * ordered_bell_number(n - i) )% m;
	
	return obn_m[n] = res;;	
}

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << ordered_bell_number(n) << endl;
	}

	return 0;
}