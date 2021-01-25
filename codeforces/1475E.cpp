#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k, a[1005], f[1005];
const ulli MOD = 1e9 + 7;
ulli combination_iterative(ulli n, ulli k){ 
    ulli C[k+1] = {0}; 
    C[0] = 1;
    for(ulli i = 1; i <= n; i++) 
        for(ulli j = min(i, k); j > 0; j--) 
            C[j] = (C[j] % MOD + C[j - 1] % MOD) % MOD;
    return C[k]; 
} 

int main(){
	io_boost;
	cin >> t;
	while(t--){
		memset(f, 0, sizeof(f));
		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> a[i], f[a[i]]++;
		sort(a, a + n, greater<int>());
		ulli ans = 1;
		int j = 0;
		for(int i = 1; i < k; i++){
			if(a[i] != a[i - 1]){
				int l = i - j;
				//cout << a[i] << " -- " << a[i - 1] << endl;
				//cout << f[a[i - 1]] << " +++ " << i - j << endl;
				ans = (ans * combination_iterative(f[a[i - 1]], i - j)) % MOD;
				//cout << ":::: " << ans << endl;
				j = i;
			}
		}

		ans = (ans * combination_iterative(f[a[k - 1]], k - j)) % MOD;

		cout << ans << endl;
	}
    return 0;
}