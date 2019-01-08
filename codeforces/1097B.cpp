#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int main() {
	int n, s = 0;
	cin >> n;
	int r[n];
	for (int i = 0; i < n; ++i){
		cin >> r[i];
		s += r[i];
	}

	if(s == 360)
		cout << "YES\n";
	else{
		for (size_t i = 0; i < (1 << n); i++){
		    int s = 0;
		    for (size_t j = 0; j < n; j++){
		        if (i & (1 << j))
		            s += r[j];
		        else
		        	s -= r[j];
		    }

		    if(s == 0 or s % 360 == 0){
		    	cout << "YES\n";
		    	return 0;
		    }
		}

		cout << "NO\n";
		return 0;
	}
    return 0;
}