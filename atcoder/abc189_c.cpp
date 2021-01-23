#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 10000, LOG2N = 14;
// MAXN: maximum amount of elements in a[], LOG2N = log2(MAXN)

// lg2[i]: log2(1), st[][]: sparse table, a[]: array of elements
int lg2[MAXN + 1], st[MAXN][LOG2N + 1], a[MAXN], N;

void build(std::function<int(int, int)> f){
    // Delete this if the query does not need it
    lg2[1] = 0;
    for(int i = 2; i <= N; i++) lg2[i] = lg2[i / 2] + 1;
    
    for(int i = 0; i < N; i++) st[i][0] = a[i];
    // st[i][j] is the answer for the range [i, i + 2^j - 1]
    for(int j = 1; j <= LOG2N; j++)
        for(int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

// Find minimum in [L, R]

lli minimum(int L, int R){
    int lg = lg2[R - L + 1];
    return min(st[L][lg], st[R - (1 << lg) + 1][lg]);
}



int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    build([](int a, int b){
        return min(a, b);
    });
    lli ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            ans = max(ans, minimum(i, j) * (j - i + 1));
        }
    }
    cout << ans << endl;
}