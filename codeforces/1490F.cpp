#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, a[200005], n;
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        map<int, int> m;
        for(int i = 0; i < n; i++) cin >> a[i], m[a[i]]++;
        
        vector<int> f;
        f.push_back(0);
        for(auto &p: m) f.push_back(p.second);
        f.resize(unique(f.begin(), f.end()) - f.begin());

        int ans = 1e9 + 5;
        for(int fq: f){
            int ansi = 0;
            for(auto &p: m){
                if(p.second < fq) ansi += p.second;
                else ansi += p.second - fq; 
            }
            ans = min(ansi, ans);
        }
        cout << ans << endl;
    }
    return 0;
}