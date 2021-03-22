# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int H, W, A, B;
bool m[16][16];

int solve(int i, int j, int a, int b){
    if(j == W) return solve(i + 1, 0, a, b);
    if(i == H) return 1;



    if(m[i][j]) return solve(i, j + 1, a, b);
    int ans = 0;
    if(a){
        if(j + 1 != W && !m[i][j + 1]){
            m[i][j] = m[i][j + 1] = true;
            ans += solve(i, j + 1, a - 1, b);
            m[i][j] = m[i][j + 1] = false;
        }
        if(i + 1 != H && !m[i + 1][j]){
            m[i][j] = m[i + 1][j] = true;
            ans += solve(i, j + 1, a - 1, b);
            m[i][j] = m[i + 1][j] = false;
        }
    }

    if(b){
        m[i][j] = true;
        ans += solve(i, j + 1, a, b - 1);
        m[i][j] = false;
    }

    return ans;

}

int main(){
    cin >> H >> W >> A >> B;
    cout << solve(0, 0, A, B) << endl;
    return 0;
}