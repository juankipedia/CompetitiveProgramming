#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m;
lli a[100][100];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        bool p = true;
        for(int i = 0; i < n; i++){
            bool pi = p;
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                if(pi && a[i][j] % 2 != 0) a[i][j]++;
                else if(!pi && a[i][j] % 2 == 0) a[i][j]++;
                pi = !pi;
            }
            p = !p;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}