# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, q, a[100005], o, z;
 
int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]) o++;
        else z++;
    }
    int t, x, k;
    while(q--){
        cin >> t;
        if(t == 1){
            cin >> x;
            x--;
            if(a[x]) o--;
            else z--;
            a[x] = 1 - a[x];
            if(a[x]) o++;
            else z++;
        }
        else{
            cin >> k;
            if(k > o) cout << 0 << endl;
            else cout << 1 << endl;
        }
    }
 
    return 0;
}