#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli oo = numeric_limits<lli>::max();
int N, M, t;
lli m[100][100];
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> N >> M;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cin >> m[i][j];
 
        lli ans = 0;
        int R = (N % 2) ? (N / 2) : (N / 2) - 1;
        int C = (M % 2) ? (M / 2) : (M / 2) - 1;
        for(int i = 0; i <= R; i++){
            for(int j = 0; j <= C; j++){
                vector<lli> v;
                v.push_back(m[i][j]);
                v.push_back(m[i][M - 1 - j]);
                v.push_back(m[N - 1 - i][j]);
                v.push_back(m[N - 1 - i][M - 1 - j]);
 
                sort(v.begin(), v.end());
                set<lli> mids;
                for(int k = 0; k < 4; k++) mids.insert(v[k]);
                mids.insert((v[0] + v[1] + v[2] + v[3]) / 4);
 
                lli s = oo, si;
 
                for(lli mid: mids){
                    si = abs(m[i][j] - mid);
                    if(j != (M - 1 - j))
                        si += abs(m[i][M - 1 - j] - mid);
                    if(i != (N - 1 - i))
                        si += abs(m[N - 1 - i][j] - mid);
                    if(j != (M - 1 - j) && i != (N - 1 - i))
                        si += abs(m[N - 1 - i][M - 1 - j] - mid);
                    s = min(si, s);
                }
                ans += s;
 
            }
        }
        cout << ans << endl;
    }
    return 0;
}