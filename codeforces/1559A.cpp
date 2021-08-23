# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, n;
lli a[105], b[105];

int main(){
    io_boost;  
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                for(int k = 0; k <= (j - i); k++)
                    a[i + k] = a[i + k] & a[j - k];
            }
        }
        lli maxi = numeric_limits<lli>::min();
        for(int l = 0; l < n; l++) maxi = max(a[l], maxi);
        cout << maxi << endl;
    }
    return 0;
}