#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
typedef unsigned long long int ulli;


int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	unordered_map<ulli, ulli> mem;
	for (int i = 0; i < n; ++i){	
		for (int j = i + 1; j < n; ++j){
			++mem[a[i] + a[j]];
		}
	}

	ulli r = 0;



	for (const auto &e: mem){
		if(e.second > r)
			r = e.second;
	}

	cout << r << endl;
    return 0;
}