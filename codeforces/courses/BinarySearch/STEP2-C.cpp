# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli n, x, y;

bool check(lli mid){
    
    lli ans = (mid / x) + ((mid < x) ? 0 : ((mid - x) / y));
    return ans >= n;
}

int main(){
    cin >> n >> x >> y;
    if(x > y) swap(x, y);
    lli lo = 0, hi = 1e12;
    while(lo < hi){
        lli mid = (lo + hi) / 2;
        if(check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
    return 0;
}