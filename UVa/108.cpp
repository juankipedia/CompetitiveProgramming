# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m[105][105], s[105][105];

int get_sum(int x, int y, int u, int v){
    int res = s[u][v];
    if(x > 0) res = res - s[x - 1][v];  
    if(y > 0) res = res - s[u][y - 1]; 
    if(x > 0 && y > 0) res = res + s[x - 1][y - 1]; 
    return res; 
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m[i][j];
    for(int i = 0; i < n; i++) s[0][i] = m[0][i];
    for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++)
            s[i][j] += m[i][j] + s[i - 1][j];
    for(int i = 0; i < n; i++)
        for(int j = 1; j < n; j++)
            s[i][j] += s[i][j - 1];
    int maxi = m[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int w = 0; j + w < n; w++){
                for(int h = 0; i + h < n; h++){
                    maxi = max(maxi, get_sum(i, j, i + h, j + w));
                }
            }
        }
    }
    cout << maxi << endl;
    return 0;
}