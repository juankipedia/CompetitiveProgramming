# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, ii[] = {0, 0, 1, -1}, jj[] = {1, -1, 0, 0};

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int m[n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                m[i][j] = -1;
        int num = 1;
        bool put = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(put) m[i][j] = num, num++;
                put = !put;
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(m[i][j] == -1)
                    m[i][j] = num, num++;

        bool ok = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int l = 0; l < 4; l++){
                    int ni = i + ii[l], nj = j + jj[l];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < n){
                        if(abs(m[ni][nj] - m[i][j]) == 1) ok = false;
                    }
                }
            }
        }
        if(ok){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++)
                    cout << m[i][j] << " ";
                cout << endl;
            }
        }
        else cout << -1 << endl;
        
    }
    return 0;
}