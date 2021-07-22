# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int k, n;
lli a[55];

bool check(lli m){
    lli b[n];
    for(int i = 0; i < n; i++) b[i] = a[i];
    int km = k;
    lli mi = m;
    for(int i = 0; i < n && km; i++){
        lli d = min(mi, b[i]);
        b[i] -= d;
        lli d1 = min(m - mi, b[i]);
        mi -= d;
        if(!mi){
            km--;
            mi = m;
            mi -= d1;
        }

    }
    return km <= 0;
}

int main(){
    cin >> k >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    lli lo = 0, hi = 1e12;
    while(lo < hi){
        lli mid = (lo + hi + 1) / 2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout <<  lo << endl;
    return 0;
}