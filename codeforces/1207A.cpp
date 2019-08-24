#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int t, b, p, f, h, c, r, n;

int main() {
	cin >> t;
	while(t--){
		cin >> b >> p >> f;
		cin >> h >> c;
		r = 0;
		if(h > c){
			n = min(b/2, p);
			r += n * h;
			b -= n * 2;
			p -= n / 2;
			n = min(b/2, f);
			r += n * c;
		}
		else{
			n = min(b/2, f);
			r += n * c;
			b -= n * 2;
			f -= n / 2;
			n = min(b/2, p);
			r += n * h;
		}
		cout << r << endl;
	}
    return 0;
}