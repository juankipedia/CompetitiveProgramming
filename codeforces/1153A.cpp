#include <bits/stdc++.h>
using namespace std;

# define endl "\n"

int main() {
	int n, t, s, d;
	cin >> n >> t;
	int p, m = std::numeric_limits<int>::max();
	for (int i = 0; i < n; ++i){
		cin >> s >> d;
		if(s >= t){
			if(s - t < m){
				m = s - t;
				p = i + 1;
			}
		}
		else{
			while(s < t)
				s += d;
			if(s - t < m){
				m = s - t;
				p = i + 1;
			}
		}
	}
	cout << p << endl;
    return 0;
}