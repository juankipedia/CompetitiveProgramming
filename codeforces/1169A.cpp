#include <bits/stdc++.h>
using namespace std;

# define endl "\n"


int main() {
	int n, a, x, b, y;
	cin >> n >> a >> x >> b >> y;
	while(true){
		if(a == b){
			cout << "YES\n";
			return 0;
		}

		if(a == x or b == y){
			cout << "NO\n";
			return 0;
		}

		if(a < n) a ++;
		else a = 1;
		if(b > 1) b --;
		else b = n;
	}
    return 0;
}