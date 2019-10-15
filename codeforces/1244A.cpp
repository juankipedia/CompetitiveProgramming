#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;


int t, a, b, c, d, k, ki, ka, kb;

int main() {
	cin >> t;
	while(t--){
		cin >> a >> b >> c >> d >> k;
		ki = 0;
		ka = 0;
		for (int i = 1; i <= k; ++i){
			ki++; ka++;
			if(i * c >= a) break;
		}

		kb = 0;
		for (int i = 1; ki + 1 <= k ; ++i){
			ki++; kb++;
			if(i * d >= b) break;
		}

		if(ka * c >= a and kb * d >= b) cout << ka << " " << kb << endl;
		else cout << -1 << endl;
	}
    return 0;
}