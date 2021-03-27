# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int ii[] = {1, -1, 0, 0}, jj[] = {0, 0, 1, -1};

int main(){
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    string m[h];
    for(int i = 0; i < h; i++) cin >> m[i];
    x--; y--;
    int ans = 1;
    for(int i = 0; i < 4; i++){
        int ni = x + ii[i], nj = y + jj[i];
        while(!(ni < 0 || ni >= h || nj < 0 || nj >= w) && m[ni][nj] != '#'){
            ans++;
            //cout << ni << " " << nj << endl;
            ni = ni +  ii[i]; nj = nj + jj[i];
        }

    }
    cout << ans << endl;
    return 0;
}