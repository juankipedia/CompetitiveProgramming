#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const int oo = numeric_limits<int>::max();
int N, M, K, m[70][70], r[71][71][71][71];

int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> m[i][j];
    for(int i = 1; i <= K; i++) r[N][0][0][i] = -oo;
    r[N][0][0][0] = 0;
    
    for(int i = N - 1; i >= 0; i--){
        for(int j = M; j >= 0; j--){
            for(int p = min(j, M / 2); p >= 0; p--){
                for(int s = K - 1; s >= 0; s--){
                    int &ans = r[i][j][p][s];
                    if(p == M / 2 || j == M) ans = r[i + 1][0][0][s];
                    else
                        ans = max(
                            m[i][j] + r[i][j + 1][p + 1][(s + m[i][j]) % K],
                            r[i][j + 1][p][s]
                        );
                }
            }
        }
    }

    cout << r[0][0][0][0] << endl;
    return 0;
}