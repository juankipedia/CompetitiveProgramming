#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


const int MAXN = 1000;
int n, k, s, ti;
int a[MAXN];
int t[MAXN + 1];


int main() {
	cin >> n >> k;
	s = (n + 1) / 2;
	for (int i = 0; i < n; ++i){
		cin >> ti;
		t[ti]++;
	}

	int c = 0;
	
	for (int i = 1; i <= k; ++i){
		if(t[i] != 0){
			s -= t[i] / 2;
			c += t[i] -(t[i] & 1);
		}
	}
	c += s;
	cout << c << endl;
    return 0;
}