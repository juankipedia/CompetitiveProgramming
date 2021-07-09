# include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        int ans;
        for(int i = 0; i < n; i++){
            if(!i) cout << 0 << endl;
            else cout << (i ^ (i - 1)) << endl;
            cin >> ans;
            if(ans) break;
        }
    }
    return 0;
}