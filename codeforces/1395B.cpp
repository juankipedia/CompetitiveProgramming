#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m, sx, sy, c, SX, SY;

int main(){
    cin >> n >> m >> sx >> sy;
    sx --; sy--;
    SX = sx; SY = sy;
    bool r = true;
    cout << sx + 1 << " " << sy + 1 << endl;
    for(int i = 0; i < m; i++)
        if(i != sy) cout << sx + 1 << " " << i + 1 << endl;

    for(int i = 0; i < n; i++){
        if(i == SX) continue;
        int j = (r) ? m - 1 : 0;
        while(true){
            if(j < 0 || j >= m)
                break;
            cout << i + 1 << " " <<  j + 1 << endl;
            if(r) j--;
            else j++;
        }
        r = !r;
    }
    
    return 0;
}