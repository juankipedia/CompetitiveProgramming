#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


int n, m;
string s;
string mi;

int aux[26];
int main() {

	cin >> n;
	cin >> s;
	cin >> m;
	vector<int> sm[26] = {std::vector<int>()};

	for (int i = 0; i < n; ++i){
		sm[s[i] - 'a'].push_back(i);
	}	

	while(m--){
		cin >> mi;
		int maxp = 0;
		int aux[26] = {0};
		for(const char &c: mi){
			int pos = c - 'a';
			maxp = max(maxp, sm[pos][aux[pos]++]);
		}
		cout << maxp + 1 << endl;
	}
    return 0;
}