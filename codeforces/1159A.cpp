#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int p = 0;
	for (int i = 0; i < n; ++i){
		if(s[i] == '-'){
			if(p == 0)
				continue;
			else
				p--;
		}
		else
			p++;
	}
	cout << p << endl;
    return 0;
}