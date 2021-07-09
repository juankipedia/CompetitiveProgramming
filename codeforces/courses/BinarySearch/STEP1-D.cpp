# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, k, a[100005];
 
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> k;
    for(int i = 0; i < k; i++){
        int l, r, la, ra;
        cin >> l >> r;
        l--;
        r++;
        int lo = 0, hi = n - 1;
        while(lo < hi){
            int mid = (lo + hi + 1) / 2;
            if(a[mid] <= l) lo = mid;
            else hi = mid - 1;
        }
        if(a[lo] <= l) la = lo;
        else la = -1;

        lo = 0; 
        hi = n - 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(a[mid] < r) lo = mid + 1;
            else hi = mid;
        }
        if(a[lo] >= r) ra = lo;
        else ra = n;
        ra--;
        la++;
        cout << ra - la + 1 <<  " ";
    }
    cout << endl;
    return 0;
}