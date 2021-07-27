# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

const int MAXN = 1e5 + 5;
int a[MAXN];
lli s[MAXN];
int n, k;

bool check(lli m){
    for(int i = 0; i < n; i++){
        if((n - i) < m) return false;
        lli sum = s[i + m] - s[i];
        lli off = m * a[i] - sum;
        if(off <= k) return true;
    }
    return false;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    for(int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
    int lo = 0, hi = MAXN;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    lli m = lo, e = -1;
    for(int i = 0; i < n; i++){
        if((n - i) < m) break;
        lli sum = s[i + m] - s[i];
        lli off = m * a[i] - sum;
        if(off <= k) e = a[i];
    }
    cout << m << " " << e << endl;
    return 0;
}