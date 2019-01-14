#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned int t;
	uint32_t n;
	cin >> t;
	while(t--){
		cin >> n;
		int x = 32; 
	    for (int i = 0; i < x; i++)  
	       n = (n ^ (1 << i));  
	    cout << n << endl; 
	}
    return 0;
}