#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m, e;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        set<int> a, b;
        for(int i = 0; i < n; i++){
            cin >> e;
            a.insert(e);
        }
        for(int i = 0; i < m; i++){
            cin >> e;
            b.insert(e);
        }

        bool f = false;
        for(const int &i: a)
            if(b.find(i) != b.end()){
                cout << "YES" << endl;
                cout << 1 << " " << i << endl;
                f = true;
                break;
            }

        if(!f) cout << "NO\n";
    }
    return 0;
}