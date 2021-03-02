# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli oo = numeric_limits<lli>::max();
int N, M;
lli K, m[105][105], s[105][105];

int main(){
    io_boost;
    int t;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> N >> M >> K;
        memset(m, 0, sizeof(m));
        memset(s, 0, sizeof(s));
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cin >> m[i][j];
        for(int i = 0; i < M; i++) s[0][i] = m[0][i];
        for(int i = 1; i < N; i++)
            for(int j = 0; j < M; j++)
                s[i][j] += m[i][j] + s[i - 1][j];
        lli area = 0, price = oo;
        for(int i = 0; i < N; i++){
            for(int ii = i; ii < N; ii++){
                lli cost = 0;
                for(int j = 0, jj = 0; j < M; j++){
                    if(i > 0) cost += s[ii][j] - s[i - 1][j];
                    else cost += s[ii][j];
                    while(jj <= j && cost > K){
                        if(i > 0) cost -= s[ii][jj] - s[i - 1][jj];
                        else cost -= s[ii][jj];
                        jj++;
                    }
                    lli a = (ii - i + 1) * (j - jj + 1);
                    if(a > area){
                        area = a;
                        price = cost;
                    }
                    else if(area == a && price > cost) price = cost;
                }
            }
        }
        cout << "Case #" << ti << ": " <<  area << " " <<  price << endl;
    }
    return 0;
}