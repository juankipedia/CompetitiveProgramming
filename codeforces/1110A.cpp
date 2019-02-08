#include <bits/stdc++.h>
using namespace std;

int main() {
	int b, k;
	cin >> b >> k;
	int a[k];
	for (int i = 0; i < k; ++i) cin >> a[i];
	if(b % 2 == 0){
		if(a[k - 1] % 2 == 0) cout << "even" << endl;
		else cout << "odd" << endl;
	}
	else{
		int c = 0;
		for (int i = 0; i < k; ++i)
			if(a[i] % 2 != 0) c ++;
		if(c % 2 == 0) cout << "even" << endl;
		else cout << "odd" << endl;	
	}
    return 0;
}