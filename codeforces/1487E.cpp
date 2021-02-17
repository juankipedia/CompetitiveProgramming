#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n[4], m[3], t[4][150005];
lli a[4][150005];
set<int> xy[3][150005];

int main(){
    cin >> n[0] >> n[1] >> n[2] >> n[3];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < n[i]; j++) cin >> a[i][j];
    for(int i = 0; i < 3; i++){
        cin >> m[i];
        for(int j = 0, x, y; j < m[i]; j++){
            cin >> x >> y;
            x--; y--;
            xy[i][x].insert(y); 
        }
    }

    for(int i = 0; i < n[3]; i++) t[3][i] = 1;
    set<pair<lli, int>> s;
    for(int i = 2; i >= 0; i--){
        for(int j = 0; j < n[i + 1]; j++)
            if(t[i + 1][j]) s.insert({a[i + 1][j], j});
        for(int j = 0; j < n[i]; j++){
            for(auto &p: s){
                if(xy[i][j].count(p.second)) continue;
                a[i][j] += p.first;
                t[i][j] = 1;
                break;
            }
        }
        s.clear();
    }

    lli res = numeric_limits<lli>::max();
    for(int i = 0; i < n[0]; i++)
        if(t[0][i]) res = min(a[0][i], res);
    if(res == numeric_limits<lli>::max()) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}