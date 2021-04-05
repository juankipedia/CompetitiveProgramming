# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, m, m1[50][50], m2[50][50];
 
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> m1[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> m2[i][j];
 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(m2[i][j] < m1[i][j]) swap(m1[i][j], m2[i][j]);

    bool ok = true;
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < m - 1; j++)
            if(m1[i][j] >= m1[i][j + 1] || m2[i][j] >= m2[i][j + 1] || 
                m1[i][j] >= m1[i + 1][j] || m2[i][j] >= m2[i + 1][j])
                ok = false;

    for(int i = 0; i < n - 1; i++)
        if(m1[i][m - 1] >= m1[i + 1][m - 1] || m2[i][m - 1] >= m2[i + 1][m - 1])
            ok = false;
    for(int i = 0; i < m - 1; i++)
        if(m2[n - 1][i] >= m2[n - 1][i + 1] || m1[n - 1][i] >= m1[n - 1][i + 1])
            ok = false;

 
    if(ok) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
 
    return 0;
}