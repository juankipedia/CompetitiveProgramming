# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N;
lli a[100005];

int main(){
    cin >> t;
    while(t--){
        cin >> N;

        for(int i = 0; i < N; i++) cin >> a[i];
        lli ans = 0, acc = 0;
        for(int i = N - 1; i >= 0; i--){
            if(a[i] < 0) acc += -a[i];
            else{
                ans += a[i] - min(acc, a[i]);
                acc -= min(acc, a[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}