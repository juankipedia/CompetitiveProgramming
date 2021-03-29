# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n;
pair<int, int> rc[200005];
 
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> rc[i].first;
        for(int i = 0; i < n; i++) cin >> rc[i].second;
        rc[n] = {1, 1};
        n++;
        int maxi = 0, ans = 0;
        map<int, int> maxip, minip;
        for(int i = 0; i < n; i++){
            if((rc[i].first - rc[i].second) % 2 == 0){
                int diff = rc[i].first - rc[i].second; 
                if(maxip.count(diff)){
                    maxip[diff] = max(rc[i].second, maxip[diff]);
                    minip[diff] = min(rc[i].second, minip[diff]);
                }
                else{
                    maxip[diff] = rc[i].second;
                    minip[diff] = rc[i].second;
                }
                
            }
            maxi = max(rc[i].first - rc[i].second, maxi);
        }
        int cntp = 0;
        for(auto &[x, y] : maxip){
            cntp += y - minip[x];
            //cout << x << "----" << y << " " << minip[x] << endl;
        }
        //cout << maxi << " ----- " << endl;
        ans = maxi / 2 + cntp;
        cout << ans << endl;
    }
    return 0;
}