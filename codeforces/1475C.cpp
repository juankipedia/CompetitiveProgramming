#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, a, b, k;
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> a >> b >> k;
        pair<int, int> p[k];
        int gf[b + 5] = {0};
        for(int i = 0; i < k; i++) cin >> p[i].first;
        for(int i = 0; i < k; i++) cin >> p[i].second;
        sort(p, p + k, [](auto &p1, auto &p2){return p1.first < p2.first;});
        for(int i = 0; i < k; i++) gf[p[i].second]++;
        int l = 0;
        lli ans = 0;
        for(int i = 0; i < k; i++){
            while(l < k && p[i].first == p[l].first){
                gf[p[l].second]--;
                l++;
            }
            ans += k - l - gf[p[i].second];
        }
        cout << ans << endl;
    }
        
    return 0;
}