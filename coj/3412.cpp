# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int n, m;
	cin >> n;
	cin >> m;
	unsigned int g[n];
	for (unsigned int i = 0; i < n; ++i) cin >> g[i];

	unsigned int c = 0, j = 0, r = 0;
	for (unsigned int i = 0; i < n; ++i){
		j = i + 1;
		c = g[i];
		while(c < m and j < n) {if(c + g[j] > m) break; c += g[j]; j++;};

		if(c == m){
			cout << m << endl;
			return 0;
		}
		else if(c < m){
			if(c > r)
				r = c;
		}

	}

	cout << r << endl;

	return 0;
}