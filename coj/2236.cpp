# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int n;
	cin >> n;
	unsigned int g[n];
	for (unsigned int i = 0; i < n; ++i) cin >> g[i];

	sort(g, g + n, [](const unsigned int A, const unsigned int B){return A > B;});

	unsigned int c = 0, c2 = 0, r = 0;

	for (unsigned int i = 0; i < n; ++i){
		c += g[i];
		r ++;
		c2 = 0;
		for (unsigned int j = i + 1; j < n; ++j){
			c2 += g[j];
		}

		if(c > c2){
			cout << r << endl;
			return 0;
		}
	}


	return 0;
}