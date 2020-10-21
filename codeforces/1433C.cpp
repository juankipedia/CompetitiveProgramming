#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli a[300000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int pos = -1;
        lli A = 0;
        for(int i = 1; i < n - 1; i++){
            if(a[i] > a[i + 1] || a[i] > a[i - 1]){
                if(a[i] > A){
                    A = a[i];
                    pos = i;
                }
            }
        }
        if(a[0] > a[1] && a[0] > A){
            A = a[0];
            pos = 0;
        }
        
        if(a[n - 1] > a[n - 2] && a[n - 1] > A){
            A = a[n - 1];
            pos = n - 1;
        }

        if(pos == -1) cout << -1 << endl;
        else cout << pos + 1 << endl;

    }
    return 0;
}