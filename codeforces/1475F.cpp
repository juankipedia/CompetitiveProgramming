#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string a[1000], b[1000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n; i++){
            if(a[0][i] != b[0][i]){
                for(int j = 0; j < n; j++)
                    if(a[j][i] == '0') a[j][i] = '1';
                    else a[j][i] = '0';
            }
        }
        for(int i = 0; i < n; i++){
            if(a[i][0] != b[i][0]){
                for(int j = 0; j < n; j++)
                    if(a[i][j] == '0') a[i][j] = '1';
                    else a[i][j] = '0';
            }
        }

        bool ok = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                if(a[i][j] != b[i][j]) ok = false;
        }

        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}