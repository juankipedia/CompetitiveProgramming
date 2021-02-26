#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli A, B, C, m[25][25][25], s[25][25][25];

lli get_sum(lli k, lli x, lli y, lli u, lli v){
    lli res = s[u][v][k]; 
    if(x > 0) res -= s[x - 1][v][k]; 
    if(y > 0) res -= s[u][y - 1][k];  
    if(x > 0 && y > 0) res += s[x - 1][y - 1][k]; 
    return res; 
} 

int t;

int main(){
    io_boost;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        cin >> A >> B >> C;
        memset(m, 0, sizeof(m));
        memset(s, 0, sizeof(s));
        for(int i = 0; i < A; i++)
            for(int j = 0; j < B; j++)
                for(int k = 0; k < C; k++)
                    cin >> m[i][j][k];
        for(int k = 0; k < C; k++){
            for(int i = 0; i< B; i++) 
                s[0][i][k] = m[0][i][k]; 
            for(int i = 1; i < A; i++) 
                for(int j = 0; j < B; j++) 
                    s[i][j][k] = m[i][j][k] + s[i - 1][j][k]; 
            for(int i = 0; i < A; i++) 
                for(int j = 1; j < B; j++) 
                    s[i][j][k] += s[i][j - 1][k]; 
        }
        lli ans = 0;
        for(int i = 0; i < A; i++){
            for(int j = 0; j < B; j++){
                for(int w = 0; i + w < A; w++){
                    for(int h = 0; j + h < B; h++){
                        lli sum = 0, maxi = 0;
                        for(int k = 0; k < C; k++){
                            sum += get_sum(k, i, j, i + w, j + h);
                            maxi = max(maxi, sum);
                            if(sum < 0) sum = 0;
                        }
                        ans = max(maxi, ans);
                    }
                }
            }
        }
        if(!ans){
            ans = m[0][0][0];
            for(int i = 0; i < A; i++){
                for(int j = 0; j < B; j++){
                    for(int k = 0; k < C; k++){
                        ans = max(m[i][j][k], ans);
                    }
                }
            }
        }
        cout << ans  << endl;
        if(ti != t - 1) cout << endl;
    }
    return 0;
}