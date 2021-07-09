# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, k, a[100005];
 
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        int lo = 0, hi = n - 1;
        while(lo < hi){
            int mid = (lo + hi + 1) / 2;
            if(a[mid] <= x) lo = mid;
            else hi = mid - 1;
        }
        if(a[lo] <= x) cout << lo + 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}