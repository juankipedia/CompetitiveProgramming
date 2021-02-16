#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m[100][100];


int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            bool l = i % 2;
            for(int j = 0; j < n; j++){
                if(i == j){
                    m[i][j] = -1;
                    continue;
                }
                else if(l) m[i][j] = 0;
                else m[i][j] = 3;
                l = !l;
            }
        }

        if(n % 2 == 0){
            for(int i = 0; i <= n - 2; i+=2){
                m[i][i + 1] = 1;
                m[i + 1][i] = 1;
            }
        }

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(m[i][j] == 3) cout << 1 << " ";
                else if(m[i][j] == 0) cout << -1 << " ";
                else cout << 0 << " ";
        cout << endl;
    }
    
    return 0;
}