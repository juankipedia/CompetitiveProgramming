#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
typedef unsigned long long int ulli;

int main() {
	ulli n, m, e;
	cin >> n >> m;
	ulli even = 0, odd = 0, even_k = 0, odd_k = 0;
	for (int i = 0; i < n; ++i){
		cin >> e;
		if(e % 2 == 0)
			even ++;
		else
			odd ++;
	} 

	for (int i = 0; i < m; ++i){
		cin >> e;
		if(e % 2 == 0)
			even_k ++;
		else
			odd_k ++;
	} 

	cout << min(even, odd_k) + min(odd, even_k) << endl;
    return 0;
}