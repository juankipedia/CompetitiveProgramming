# include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;

ui a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(){
	ui n;
	cin >> n;
	ui m[n][n];
	for (ui i = 0; i < n; ++i)
		for (ui j = 0; j < n; ++j)
			cin >> m[i][j];
	int min = numeric_limits<int>::max();
	ui r[n];
	do {
		int sum = 0;
    	for (ui i = 0; i < n - 1; ++i)
    		sum += m[a[i] - 1][a[i + 1] - 1];
    	if(sum < min){
    		min = sum;
    		for (int i = 0; i < n; ++i) r[i] = a[i];
    	}
  	} while (next_permutation(a, a + n));

  	for (int i = 0; i < n; ++i) cout << r[i] << ' ';
  	cout << "\n";
	return 0;
} 