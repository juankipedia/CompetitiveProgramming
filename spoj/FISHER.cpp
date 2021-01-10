#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const int oo = numeric_limits<int>::max();
const int MAXN = 50;
int N, T, s[MAXN][MAXN], p[MAXN][MAXN];
bool mb[MAXN][1000];
pair<lli, int> m[MAXN][1000];
 
pair<lli, int> dp(int v, int t){
    if(t > T) return {oo, oo};
    if(v == N - 1) return {0, t};
    if(mb[v][t]) return m[v][t];
    mb[v][t] = true;
    int tans = oo;
    lli pans = oo;
    for(int i = 0; i < N; i++){
        if(i != v){
            auto cur = dp(i, t + s[v][i]);
            if((cur.first + p[v][i]) < pans){
                pans = cur.first + p[v][i];
                tans = cur.second;
            }
        }
    }
    return m[v][t] = {pans, tans};
}
 
int main(){
    io_boost;
    while(cin >> N >> T && N != 0){
        memset(mb, false, sizeof(mb));
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> s[i][j];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> p[i][j];
        auto res = dp(0, 0);
        cout << res.first << " " << res.second << endl;
    }
    return 0;
} 