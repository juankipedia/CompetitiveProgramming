# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[5005], c[5005];

int main(){
    cin >> t;
    while(t--){
		cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i], c[i] = 0;
		lli ans = 0;
        for(int i = 0; i < n; i++){
            if(c[i] < a[i] - 1) ans += a[i] - 1 - c[i];
            else c[i + 1] += c[i] - a[i] + 1; 
            for(int j = i + 2; j < min(n, a[i] + i + 1); j++) c[j]++;
        }
		cout << ans << endl;
	}

    return 0;
}