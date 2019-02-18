#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

size_t r = 0, s;

int l_d(int n, int a[]){
	int x;  
    for (int i = 1; i <= sqrt(n); i++){ 
        if (n % i == 0){ 
            if (n / i == i){
            	x = i;
            	size_t r_i = s - (n - n / x) + (a[0] * x - a[0]);
				if( r_i < r) r = r_i;
            }
            else{
            	x = i;
            	size_t r_i = s - (n - n / x) + (a[0] * x - a[0]);
				if( r_i < r) r = r_i;
				x = n / i;
            	r_i = s - (n - n / x) + (a[0] * x - a[0]);
				if( r_i < r) r = r_i;
            }
        } 
    }

    return r; 
} 


int main() {
	io_boost;
	int n, x = 1;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		r += a[i];
	}
	s = r;
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--) l_d(a[i], a);
	cout << r << endl;
    return 0;
}