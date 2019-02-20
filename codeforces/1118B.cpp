#include <bits/stdc++.h>
using namespace std;

# define endl "\n"

typedef unsigned long long int ulli;


int main() {
	ulli n;
	cin >> n;
	ulli a[n];
	ulli even = 0, odd = 0;
	pair<ulli, ulli> m[n];
	for (ulli i = 1; i <= n; ++i) {
		cin >> a[i - 1];
		if(i % 2 == 0)
			even += a[i - 1];
		else
			odd += a[i - 1];
		m[i - 1] = make_pair(odd, even);
	}
	ulli r = 0;
	for (ulli i = 1; i <= n; ++i){
		if(i % 2 == 0){
			if(even + m[i - 1].first - m[i - 1].second == odd - m[i - 1].first + m[i - 1].second - a[i - 1])
				r++;
		}
		else{
			
			if(odd - m[i - 1].first + m[i - 1].second == even + m[i - 1].first - m[i - 1].second - a[i - 1])
				r++;
		}
	}
	cout << r << endl;
    return 0;
}