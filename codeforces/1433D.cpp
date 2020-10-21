#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli a[5000];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cin >> a[0];
        bool e = true;
        for(int i = 1; i < n; i++){
            cin >> a[i];
            if(a[i] != a[0]) e = false;
        }
        if(e){cout << "NO" << endl; continue;}
        lli k1 = a[0], k2, p;
        for(int i = 0; i < n; i++){
            if(a[i] != k1){
                k2 = a[i];
                p = i;
                break;
            }
        }
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)
            if(a[i] != k1) cout << 1 << " " << i + 1 << endl; 

        for(int i = 1; i < n; i++)
            if(a[i] == k1) cout << p + 1 << " " << i + 1 << endl;

    }
    return 0;
}