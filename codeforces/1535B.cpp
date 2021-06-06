# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[2005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> e, o;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] % 2) o.push_back(a[i]);
            else e.push_back(a[i]);
        }
        for(int i = 0; i < n; i++){
            if(e.empty()) a[i] = *o.rbegin(), o.pop_back();
            else a[i] = *e.rbegin(), e.pop_back();
        }
        lli ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(__gcd(a[i], 2 * a[j]) != 1) ans++;

        cout << ans << endl;
    }
    return 0;
}