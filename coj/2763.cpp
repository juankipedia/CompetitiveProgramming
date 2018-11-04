# include <bits/stdc++.h>
using namespace std;

void print_level_order_path(unsigned int t[], const unsigned int & k, const unsigned int &n){
	for (unsigned int i = 0; i < k; ++i){
		unsigned int pos = ((1 << (k - i)) - 1) / 2;
		unsigned int offset = pos * 2 + 2;
		for (unsigned int j = pos; j < n; j += offset){ 
			cout << t[j];
			if(j + offset < n)
				cout << " ";
		}
		cout << endl;
	}
}

int main(){

	unsigned int k, n;
	cin >> k;
	n = (1 << k) - 1;
	unsigned int t[n];
	for (int i = 0; i < n; ++i) cin >> t[i];
	print_level_order_path(t, k, n);
	return 0;
}