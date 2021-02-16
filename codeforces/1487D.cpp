#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int t;
lli n;

bool check(int c){
    lli odd = c * 2 - 1;
    lli b = (odd * odd - 1) / 2, a2 = odd * odd;
    return b <= n && (a2 - b) <= n;  
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        int lo = 0, hi = n / 2 + 1;
        while(lo < hi){
            int mid = lo + (hi - lo + 1) / 2;
            if(check(mid)) lo = mid;
            else hi = mid - 1;

        }
        cout << lo - 1 << endl;
    }
    return 0;
}