# include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	unsigned int n, i;
	cin >> n;
	i = n;
	unsigned int p[n];
	while(i --){
		cin >> p[i];
	}
	sort(p, p + n);
	unsigned int d = p[1] - p[0];
	for (i = 1; i < n - 1; ++i){
		if (p[i + 1] - p[i] != d){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}