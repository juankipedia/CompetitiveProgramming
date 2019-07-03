#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;


int T;
ulli n, s, t;

int main() {
	cin >> T;
	while(T--){
		cin >> n >> s >> t;
		if(n == s and s == t)
			cout << 1 << endl;
		else if(s + t == n){
			ulli r = 0;
			r  = max(s, t) + 1;
			cout << r << endl;
		}
		else{
			ulli d = s + t - n, r = 0;
			s -= d;
			t -= d; 
			r  = max(s, t) + 1;
			cout << r << endl;
		}
	}
    return 0;
}