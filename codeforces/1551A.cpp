# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
 
int t, n;
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        double p = double(n) / 3;
        int d = n / 3;
        p -= n/3;
        if(0.5 <= p) d++;
        cout << n - 2 * (d) << " " << d << endl;
    }
}