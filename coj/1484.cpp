# include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	unsigned int n, p = 0;
	double t, h;
	cin >> n;
	cin >> h;
	for (unsigned int i = 1; i < n; ++i){
		cin >> t;
		if(t >= h){
			h = t;
			p = i;
		}
	}
	
	cout << p  + 1 << endl;

	return 0;
}