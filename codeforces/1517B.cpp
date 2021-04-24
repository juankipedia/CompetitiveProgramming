# include <bits/stdc++.h>
using namespace std;

int t, n, m, g[105][105], v[105][105];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
                v[i][j] = false;
            }
        }
        for(int i = 0; i < n; i++){
            sort(g[i], g[i] + m, greater<int>());
        }
        for(int i = 0; i < m; i++){
            int b = numeric_limits<int>::max(), pi = n, pj = m;
            for(int j = 0; j < n; j++){
                for(int k = 0; k < m; k++){
                    if(!v[j][k] && g[j][k] < b){
                        b = g[j][k];
                        pi = j;
                        pj = k;
                    }
                }
            }
            if(pi != n){
                swap(g[pi][i], g[pi][pj]);
                v[pi][i] = true;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}