#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 100005;
int t, n;
lli c[MAXN], a[MAXN], b[MAXN];


lli dp(int i){

}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> c[i];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(b[i] < a[i]) swap(a[i], b[i]);
        }
        lli cur = b[1] - a[1] + 2, ans = 0;
        for(int i = 2; i < n; i++){
            if(b[i] == a[i]){
                cur += c[i - 1] - 1;
                ans = max(ans, cur);
                cur = 2;
            }
            else{
                ans = max(ans, cur + c[i - 1] - 1);
                cur = max(b[i] - a[i], cur + a[i] - 1 + c[i - 1] - b[i]) + 2;
            }
        }
        cur += c[n - 1] - 1;
        ans = max(ans, cur);
        cout << ans << endl;
    }
    

    return 0;
}