#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


const int MAX = 200;
int q, n;
int p[MAX];

int main() {
	cin >> q;
	while(q--){
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> p[i];
		bool c = true;
		if(n == 1){
			cout << "YES" << endl;
			continue;
		}

		if(p[0] != n){
			c = ((p[0] + 1) == p[1]);
		}
		else{
			c = (p[0] == (p[n - 1] + 1));
		}

		//cout << c << endl;

		bool r = true;
		for (int i = 0; i < n - 1; ++i){
			if(c){
				if(p[i] + 1 != p[i + 1] and p[i] != n){
					r = false;
					break;
				}
			}
			else{
				if(p[i] - 1 != p[i + 1] and p[i] != 1){
					r = false;
					break;
				}
			}
		}

		if(r) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    return 0;
}