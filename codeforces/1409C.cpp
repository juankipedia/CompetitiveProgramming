#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, x, y;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        int mini = 0, maxi = numeric_limits<int>::max(), bi = 0;  
        for(int i = 1; i <= (y - x); i++){
            if((y - x) % i) continue;
            int m = (y - x) / i + 1;
            if(m > n) continue;
            int l = x;
            while(m < n){
                l -= i;
                if(l <= 0) break;
                m++;
            }
            if(l <= 0) l += i;
            int r = y;
            while(m < n){
                r += i;
                m++;
            }

            if(r < maxi){
                bi = i;
                mini = l;
                maxi = r;
            }
            
        }
        for(int i = 0; i < n; i++){
            cout << mini << " ";
            mini += bi;
        }
        cout << endl;
    }
    return 0;
}