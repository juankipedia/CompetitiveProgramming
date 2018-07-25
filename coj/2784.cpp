# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int n;
	scanf("%u", &n);
	unsigned int g[n];
	for (unsigned int i = 0; i < n; ++i){
		scanf("%u", &g[i]);
	}
	sort(g, g + n);
	printf("%u ", g[n - 1]);
	for (unsigned int i = 0; i < n - 1; ++i){
		printf("%u ", g[i]);
	}
	cout << "\n";
	return 0;
}