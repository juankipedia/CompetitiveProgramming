# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;
int t, n, a[MAXN];


int main(){
    cin >> t;
    while(t--){
        cin >> n;
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++) cin >> a[i], m[a[i]].push_back(i);
        lli ans = 0;
        for(auto &[e, p] : m){
            lli sum = 0;
            for(auto pos: p) sum += n - pos;
            for(auto pos: p){
                sum -= n - pos;
                ans += (pos + 1) * sum;
            }
        }
        cout << ans << endl;
    
    }
    return 0;
}