#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
int q, n;
ulli s, ai;

int main() {
	cin >> q;
	while(q--){
		cin >> n;
		s = 0;
		for (int i = 0; i < n; ++i){
			cin >> ai;
			s += ai;	
		}
		while(s % n != 0) s++;
		cout << s / n << endl;
	}
    return 0;
}