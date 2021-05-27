# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n, a[100005];
 
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int z = 0, p = 1e9 + 5, ne = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] < 0) ne++;
            if(a[i] == 0) z++;
            if(a[i] > 0) p = min(p, a[i]);
        }
        if(z <= 1 && p != 1e9 + 5){
            vector<int> v;
            bool ok = true;
            for(int i = 0; i < n; i++)
                if(a[i] < 0) v.push_back(-a[i]);
            sort(v.begin(), v.end());
            for(int i = 1; i < v.size(); i++) if((v[i] - v[i - 1]) < p) ok = false;
            if(z && v.size() && v[0] < p) ok = false;
            if(ok) cout << ne + z + 1 << endl;
            else cout << ne + z << endl;
        }
        else cout << ne + z << endl;
    }
    return 0;
}