# include <bits/stdc++.h>
using namespace std;

int main (){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	unsigned int t, n, i, p[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	cin >> t;
	for (i = 0; i < t; ++i){
		cin >> n;
		cout << "Case #" << i + 1<<": " << p[n - 1] << "\n";
	}

	return 0;
}