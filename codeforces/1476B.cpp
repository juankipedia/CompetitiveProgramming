# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli p[105], k;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> p[i];
        lli sum = p[0], ans = 0;
        for(int i = 1; i < n; i++){
            if(sum * k < 100LL * p[i]){
                lli w = 100LL * p[i]; 
                ans += ((w + k - 1) / k) - sum;
                sum = (w + k - 1) / k;
            }
            sum += p[i];
        }
        cout << ans << endl;
    }
    return 0;
}