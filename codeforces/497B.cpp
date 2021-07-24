# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

const int MAXN = 1e5;
int n, a[MAXN], b[MAXN];

int main(){
    cin >> n;
    for(int i = 0, si; i < n; i++){
        cin >> si;
        if(si == 1) a[i] = 1;
        else b[i] = 1;
    }
    for(int i = 1; i < n; i++)
        a[i] = a[i - 1] + a[i],
        b[i] = b[i - 1] + b[i];

    vector<pair<int, int>> ans;
    for(int t = 1; t <= n; t++){
        int sa = 0, sb = 0, wa = 0, wb = 0;
        int f = -1;
        while(true){
            int i = lower_bound(a, a + n, t + sa) - a,
                j = lower_bound(b, b + n, t + sb) - b;
            if(i == n && j == n){ f = -1; break; }
            if(i > j){
                if(j == n - 1){
                    wb++;
                    f = 1;
                    break;
                }
                else{
                    sa = a[j];
                    sb = b[j];
                    wb++;
                }
            }
            else{
                if(i == n - 1){
                    wa++;
                    f = 0;
                    break;
                }
                else{
                    sa = a[i];
                    sb = b[i];
                    wa++;
                }
            }
        }
        if(f == -1) continue;
        if(f && wb > wa) ans.push_back({wb, t});
        else if(!f && wa > wb) ans.push_back({wa, t});
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto [s, t] : ans) cout << s << " " << t << endl; 
    return 0;
}