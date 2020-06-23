# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

const int INF = numeric_limits<int>::max();

int C, c, N, K, price[100];
int m[100][100], mc[100][100];

int f(int n, int k){
    if(n == N && k != K) return -1;
    if(k > K) return -1;
    if(k == K) return 0;
    if(mc[n][k] == c) return m[n][k];
    mc[n][k] = c;
    int ans = INF;
    for(int i = 0; i < K; i++){
        if(price[i] != -1){
            int ret = f(n + 1, k + i + 1);
            if(ret != -1)
                ans = min(price[i] + ret, ans);
        }
    }
    m[n][k] = (ans != INF) ? ans : -1;
    return m[n][k];
}

int main(){
    io_boost;
    cin >> C;
    for(c = 1; c <= C; c++){
        cin >> N >> K;
        for(int i = 0; i < K; i++)cin >> price[i];
        cout << f(0, 0) << endl;
    }
    
    return 0;
}