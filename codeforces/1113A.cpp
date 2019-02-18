#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main() {
	io_boost;
	int n, v;
	cin >> n >> v;
	int c = 0;
	if(n <= v) c += n - 1; else c += v;
	int v_i  = v - 1;
	for (int i = 2; i < n; ++i){
		if(v_i < n - i){
			c += (v - v_i) * i;
			v_i = v;
		}
		v_i --;
	}
	cout << c << endl;
    return 0;
}