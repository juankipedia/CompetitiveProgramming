#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 2000 + 5;
int S, N, w[MAXN], v[MAXN], memo[MAXN][MAXN];

// este tiene complejidad O(S * N);
int f(int si, int i){
    if(i >= N) return 0;
    if(si == S) return 0;
    if(memo[si][i] != -1) return memo[si][i];
    if(si + w[i] > S) return memo[si][i] = f(si, i + 1);
    else return memo[si][i] = max(f(si, i + 1), v[i] + f(si + w[i], i + 1));
}

int main(){
    io_boost;
    cin >> S >> N;
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < N; i++)
        cin >> w[i] >> v[i];
    cout << f(0, 0) << endl;
    return 0;
}