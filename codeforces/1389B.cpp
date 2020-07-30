#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k, z, a[100000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k >> z;
        for(int i = 0; i < n; i++) cin >> a[i];
       
        int r = 0, kr = 0;
        lli ps[n], maxi = 0;
        ps[0] = a[0]; 
        for(int i = 1; i < n && i <= k; i++)
            ps[i] = a[i] + ps[i - 1];
        for(int i = 1; i < n && i <= k; i++){
            lli pans = ps[i];
            int K = k - i;
            
            bool l = true;
            int j = 0;
            while(j < z && K){
                
                if(l){
                    pans += a[i - 1];
                    j++;
                    K--;
                    l = false;
                }
                else{
                    pans += a[i];
                    K--;
                    l = true;
                }
            }
            if(l) r = i;
            else r = i - 1;
            pans += ps[r + K] - ps[r];
            maxi = max(pans, maxi);
        }

        cout << maxi << endl;

    }
    return 0;
}