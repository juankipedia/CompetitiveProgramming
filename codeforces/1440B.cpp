#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n, k;
lli a[1000006];
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n*k; i++){
            cin >> a[i];
        }
        int offset = n / 2;
        int j = n * k;
        lli s = 0;
        for(int i = 0; i < k; i++){
            s += a[j - (offset + 1)];
            j = j - (offset + 1);
        }
        cout << s << endl;
    }
    return 0;
}