# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const int MAXN = 5200;

int m[MAXN][MAXN], sum[MAXN][MAXN], N;

void build(){   
    for(int i = 0; i < N; i++) sum[0][i] = m[0][i];
    for(int i = 1; i < N; i++)
        for(int j = 0; j < N; j++)
            sum[i][j] = m[i][j] + sum[i - 1][j];
    for(int i = 0; i < N; i++)
        for(int j = 1; j < N; j++)
            sum[i][j] += sum[i][j-1];
}

int query(int x1, int y1, int x2, int y2){
    int res = sum[x2][y2];
    if(x1 > 0) res = res - sum[x1 - 1][y2];
    if(y1 > 0) res = res - sum[x2][y1 - 1];
    if(x1 > 0 && y1 > 0) res = res + sum[x1 - 1][y1 - 1];
    return res;
}

map<char, int> hex_map = {
    {'0', 0}, {'1',1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
    {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11},
    {'C', 12}, {'D', 13},  {'E', 14}, {'F', 15}
};

int main(){
    io_boost;
    cin >> N;
    string row;
    for(int i = 0; i < N; i++){
        cin >> row;
        int l = 0;
        for(int j = 0; j < N / 4; j++){
            int e = hex_map[row[j]];
            for(int k = 3; k >= 0; k--, l++)
                m[i][l] = ((1 << k) & e) ? 1 : 0;
        }
    }
    build();
    int ans = 1;
    for(int x = 1; x <= N; x++){
        if(N % x) continue;
        bool f = true;
        for(int i = 0; i < N; i += x){
            for(int j = 0; j < N; j += x){
                int s = query(i, j, i + x - 1, j + x - 1);
                if(s != x * x && s != 0){
                    f = false;
                    break;
                }
            }
            if(!f) break;
        }
        if(f) ans = x;
    }
    cout << ans << endl;
    return 0;
}