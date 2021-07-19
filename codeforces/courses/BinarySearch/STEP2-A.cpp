# include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;

ulli n, w, h;
 
int main(){
    cin >> w >> h >> n;
    ulli lo = 0, hi = numeric_limits<lli>::max();
    while(lo < hi){
        ulli mid = (lo + hi) / 2;
        if(((mid / w) * (mid / h)) >= n) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
    return 0;
}