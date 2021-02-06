#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m, v[3];
string g[1000];
int S[2][1000];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(S, -1, sizeof(S));
        for(int i = 0; i < n; i++){
            cin >> g[i];
            for(int j = 0; j < n; j++){
                if(g[i][j] == 'a') S[0][j] = i;
                if(g[i][j] == 'b') S[1][j] = i;
            }
        }
        int bi = -1, bj = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && g[i][j] == g[j][i]){
                    bi = i + 1; bj = j + 1;
                    break;
                }
            }
        }

        if((m % 2) == 0 && bi == -1){
            if(n <= 2){
                cout << "NO" << endl;
                continue;
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){

                    if(g[i][j] == 'a' && S[0][i] != -1){
                        v[0] = S[0][i] + 1;
                        v[1] = i + 1;
                        v[2] = j + 1;
                        break;
                    }
                    if(g[i][j] == 'b' && S[1][i] != -1){
                        v[0] = S[1][i] + 1;
                        v[1] = i + 1;
                        v[2] = j + 1;
                        break;
                    }
                }
            }

            cout << "YES" << endl;
            int j = 0;
            if(((m / 2) % 2) == 0) j = 1;
            bool in = true;
            for(int i = 0; i < m + 1; i++){
                cout << v[j] << " ";
                if(j == 2) in = false;
                if(j == 0) in = true;
                if(in) j++;
                else j--;
            }
            cout << endl;
            continue;
        }
        else if(bi == -1){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i != j && g[i][j] != g[j][i]){
                        bi = i + 1; bj = j + 1;
                        break;
                    }
                }
            }
        }
        cout << "YES" << endl;
        for(int i = 0; i < m + 1; i++)
            if(i % 2) cout << bi << " ";
            else cout << bj << " ";
        cout << endl;
    }
    
    return 0;
}