# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int N, K;
vector<string> m;
set<vector<string>> v;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};


int go(int k){
    if(v.count(m)) return 0;
    v.insert(m);
    if(k == K) return 1;
    vector<pair<int, int>> next;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(m[i][j] == '.')
                for(int l = 0; l < 4; l++){
                    int ni = i + di[l], nj = j + dj[l];
                    if(ni >= 0 && ni < N && nj >= 0 && nj < N && m[ni][nj] == '@')
                        next.push_back({i, j});
                }
    int ans = 0;
    for(auto &[i, j]: next){
        m[i][j] = '@';
        ans += go(k + 1);
        m[i][j] = '.';
    }
    return ans;
}

int main(){
    io_boost;
    cin >> N >> K;
    m.resize(N);
    int ans = 0;
    for(int i = 0; i < N; i++) cin >> m[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(m[i][j] == '.'){
                m[i][j] = '@';
                ans += go(1);
                m[i][j] = '.';
            }
        }
    }
    cout << ans << endl;
    return 0;
}