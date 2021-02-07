#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n;
 
int main(){
    cin >> n;
    int lo = 1, hi = n, qi, qi1;
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        cout << "? " << mid << endl;
        cout.flush();
        cin >> qi;
        cout << "? " << mid + 1 << endl;
        cout.flush();
        cin >> qi1;
        if(qi > qi1) lo = mid + 1;
        else hi = mid;
    }
    cout << "! " << lo << endl;
    cout.flush();
    return 0;
}