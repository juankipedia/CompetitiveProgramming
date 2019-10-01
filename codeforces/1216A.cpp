#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;

int n;
string s;

int main() {
	cin >> n;
	cin >> s;
	char c = (s[0] == 'a')?('b'):('a');
	int cc = 0;
	for (int i = 1; i < n; ++i){
		if(s[i] != c and i % 2 != 0){
			cc++;
			s[i] = c;
		}
		else if(i % 2 == 0)c = (s[i] == 'a')?('b'):('a');
	}
	cout << cc << endl << s << endl;
    return 0;
}