#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, d;
        cin >> n >> d;
        int a[n];
        bool f = true;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > d) f = false;
        }
        if(!f){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i != j && (a[i] + a[j]) <= d){
                        f = true;
                        break;
                    }
                }
            }
            if(f) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
    
    return 0;
}