#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


lli gcd(lli a, lli b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int n;
lli a[250000];
map<lli, lli> m;

int main(){
    cin >> n;
    lli maxi = 0;
    for(int i = 0; i < n * n; i++)
        cin >> a[i], m[a[i]]++;
    sort(a, a + (n * n), greater<lli>());
    lli ans[n];
    ans[0] = a[0];
    m[a[0]]--;
    for(int i = 1, j = 1; i < n *n; i++){
        if(m[a[i]]){
            m[a[i]]--;
            for(int k = 0; k < j; k++)
                m[gcd(a[i], ans[k])] -= 2;
            ans[j++] = a[i];
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}