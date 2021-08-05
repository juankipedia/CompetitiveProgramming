# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int n, m, a[200005];

int main(){
    cin >> n >> m;
    int d = 0;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        if(u > v) swap(u, v);
        if(a[u] == 0) d++;
        a[u]++;
    }
    int q;
    cin >> q;
    while(q--){
        int u, v, p;
        cin >> p;
        if(p == 3){
            cout << n - d << endl;
            continue;
        }
        cin >> u >> v;
        u--; v--;
        if(u > v) swap(u, v);
        if(p == 1){
            if(a[u] == 0) d++;
            a[u]++;
        }
        else{
            a[u]--;
            if(!a[u]) d--;
        }
    }
    return 0;
}