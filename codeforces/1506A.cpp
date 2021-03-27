# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
lli t, n, m, x;
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> m >> x;
        lli j = 1, i = (x - 1) / n;
        j += ((x - 1) / n) * n;
        if(j > x){
            j -= n;
            i--;
        }

        lli k = x - j;
        //if(k > 0) k--;
        // for(; k < n && j < x; k++, j++);

        //cout << i << " " << k << endl;
 
        lli r = 1 + k * m + i;
 
        cout << r << endl;
    }
    return 0;
}