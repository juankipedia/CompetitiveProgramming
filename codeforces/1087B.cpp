# include <bits/stdc++.h>
using namespace std;

int main(){
	long long unsigned int n, k, c, r, m;
	cin >> n >> k;
	m = std::numeric_limits<long long unsigned int>::max();
	for(long long unsigned int i = 1; i <= n ; i++){
		if( n % i == 0){
			c = i; r = n / i;
			if(r < k) m = min(m, k * c + r); 
		}
	}

	cout << m << endl;
}