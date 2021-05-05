# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, l, r, s[1000000];
int cc = 1;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> l >> r;
        int left[n] = {0}, right[n] = {0};
        for(int i = 0; i < l; i++) cin >> s[i], left[--s[i]]++;
        for(int i = 0; i < r; i++) cin >> s[i + l], right[--s[i + l]]++;

        for(int i = 0; i < n; i++){
            int mini = min(left[i], right[i]);
            left[i] -= mini;
            right[i] -= mini;
        }
        int ans = 0;
        vector<pair<int, int>> lv, rv;
        int lo = 0, ro = 0;
        for(int i = 0; i < n; i++){
            if(left[i] && left[i] % 2){
                if(left[i] > 1) lv.push_back({left[i] - 1, i});
                lo++;
            }
            else if(left[i]) lv.push_back({left[i], i});
            if(right[i] && right[i] % 2){
                if(right[i] > 1) rv.push_back({right[i] - 1, i});
                ro++;
            }
            else if(right[i]) rv.push_back({right[i], i});
        }

        

        if(lo > ro) lo -= ro, ans += ro, ro = 0;
        else ro -= lo, ans += lo, lo = 0;

        vector<pair<int, int>> &v = (ro == 0) ? rv : lv;
        int a = ro == 0 ? lo : ro;
    
        while(a && !v.empty()){
            int &aux = v.rbegin()->first;
            int mini = min(a, aux);
            ans += mini;
            a -= mini;
            aux -= mini;
            if(aux == 0) v.pop_back();
        }

        ans += a;

        for(auto p: lv) ans += p.first / 2;
        for(auto p: rv) ans += p.first / 2;

        cout << ans << endl;
    }
    return 0;
}