# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int n, k;
lli a[100005];

bool check(lli sum){
    lli s = 0;
    int ki = 0;
    for(int i = 0; i < n; i++)
        if((s + a[i]) > sum){
            if(a[i] > sum) return false;
            s = a[i];
            ki++;
        }
        else s += a[i];
    ki++;
    return ki <= k;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    lli lo = 0, hi = 1e18;
    while(lo < hi){
        lli sum = (lo + hi) / 2;
        if(check(sum)) hi = sum;
        else lo = sum + 1;
    }
    cout << lo << endl;
    return 0;
}