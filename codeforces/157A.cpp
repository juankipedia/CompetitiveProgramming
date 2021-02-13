#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
int m[40][40];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m[i][j];
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int sc = 0, sr = 0;
            for(int c = 0; c < n; c++){
                sr += m[i][c];
                sc += m[c][j];
            }
            if(sc > sr) ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}