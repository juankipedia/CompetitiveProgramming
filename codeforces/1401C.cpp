#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, t;
lli a[100000], b[100000];
lli mini;

lli gcd(lli a, lli b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        mini = 1000000007;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
            mini = min(a[i], mini);
        }
        sort(b, b + n);
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(b[i] != a[i] && a[i] % mini){
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}