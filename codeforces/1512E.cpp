# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, l, r, s;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> l >> r >> s;
        l--; r--;
        int p[n], len = r - l + 1, diff = n - (r - l + 1);

        if((len * (len + 1) / 2)  + diff * len < s || (len * (len + 1) / 2) > s){
            cout << -1 << endl;
            continue;
        }
        for(int i = l, j = 1; i <= r; i++, j++) p[i] = j;
        if((len * (len + 1) / 2) < s){
            s -= (len * (len + 1) / 2);
            for(int i = r ; i >= l, s; i--){
                p[i] += min(diff, s);
                s -= min(diff, s);
            }
        }

        bool pb[n + 1] = {false};
        for(int i = l; i <= r; i++) pb[p[i]] = true;
        for(int i = 0, j = 1; i < n; i++){
            if(i >= l && i <= r) continue;
            while(j <= n && pb[j]) j++;
            p[i] = j;
            j++;
        }
        for(int i = 0; i < n; i++) cout << p[i] << " ";
        cout << endl;
        
    }
    return 0;
}