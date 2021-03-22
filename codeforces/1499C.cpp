# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, t;
lli a[100000];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        lli b[n];
        b[0] = n; b[1] = n;
        lli ans = n * a[0] + n * a[1], sum;
        sum = ans;
        int x = 0, y = 1;
        bool xt = true;
        for(int i = 2; i < n; i++){
            int pos = x;
            if(!xt) pos = y;
            if(a[pos] > a[i]){
                sum -= (b[pos] - 1) * a[pos];
                sum += (b[pos] - 1) * a[i];
                b[i] = b[pos] - 1;
                b[pos] = 1;
                if(xt) x = i;
                else y = i;
            }
            else{
                sum -= a[pos];
                sum += a[i];
                b[pos]--;
                b[i] = 1;
            }
            ans = min(ans, sum);
            xt = !xt;
        }
        cout << ans << endl;
    }
    return 0;
}