#include <bits/stdc++.h>
using namespace std;

# define endl "\n"


int main() {

	int n, m, k;
	cin >> n >> m >> k;
	int p[n];
	int s[n];
	for (int i = 0; i < n; ++i){
		cin >> p[i];
	}

	for (int i = 0; i < n; ++i){
		cin >> s[i];
	}

	unordered_map<int,set<int> > mem;
	for (int i = 0; i < n; ++i){mem[s[i]].insert(p[i]);};

		int r = 0;
	int k_i;
	for (int i = 0; i < k; ++i){
		cin >> k_i;
		if(*(mem[s[k_i - 1]].rbegin()) != p[k_i - 1])
			r++;
	}

	cout << r << endl;
    return 0;
}