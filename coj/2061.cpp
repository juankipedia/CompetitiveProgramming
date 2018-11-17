# include <bits/stdc++.h>
using namespace std;

size_t k = 1000000007;


size_t pw(size_t x, size_t i) 
{ 
    size_t res = 1;
    x = x % k; 
    while (i > 0) {  
        if (i & 1) 
            res = (res*x) % k; 
  
        i = i >> 1 ;
        x = (x*x) % k;   
    } 
    return res; 
} 

int main(){
	size_t t, x, n;
	cin >> t;
	while(t--){
		cin >> x >> n;
		if(x == 1) cout << n + 1 << endl;
		else{
			size_t num = pw(x - 1, k - 2), d = (pw(x, n + 1) - 1 + k) % k;
			d = (d * num) % k;
			cout << d << endl;
		}
	}
	return 0;
}