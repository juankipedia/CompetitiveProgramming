#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;

int main() {
	int n, h, m;
	cin >> n >> h >> m;
	tuple<int, int, int> r[m];
	int l, r_, x;
	for (int i = 0; i < m; ++i){
		cin >> l >> r_ >> x;
		r[i] = make_tuple(l, r_, x);
	}

	ulli p = 0;
	for (int i = 1; i <= n ; ++i){
		set<int> s;
		for (int j = 0; j < m; ++j){
			if(i >= get<0>(r[j]) and i <= get<1>(r[j])){
				
				s.insert(get<2>(r[j]));

			}
		}
		
		if(s.size() == 0)
			p += h * h;
		else{
			int max = *(s.begin());
			p += max * max;
		}
	}

	cout << p << endl;
    return 0;
}