#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli a[3], d;
int main() {
	cin >> a[0] >> a[1] >> a[2] >> d;
	sort(a, a+ 3);
	if(abs(a[2] - a[1]) >= d and abs(a[1]- a[0]) >= d){
		cout << 0 << endl;
		return 0;
	}
	ui s = 0;

	if(abs(a[2] - a[1]) < d){
				s+= d - abs(a[2] - a[1]);
		a[2] += d - abs(a[2] - a[1]);
	}


	if(abs(a[1]- a[0]) < d){
		s+= d - abs(a[1]- a[0]);
		a[0]-= d - abs(a[1]- a[0]);
		
	}
	//cout << a[0] << " " << a[1] << " " << a[2] << endl;
	cout << s << endl;
	return 0;
}