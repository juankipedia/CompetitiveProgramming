#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const ulli INF = numeric_limits<int>::max();
lli k, n, A, B, T;
ulli ab[200005], a[200005], b[200005];


int main(){
    io_boost;
    cin >> n >> k;
    int I = 0, J = 0, K = 0;
    for(int i = 0; i < n; i ++){
        cin >> T >> A >> B;
        if(A == 1 && B == 1) ab[I] = T, I++;
        else if(A == 1) a[J] = T, J++;
        else if(B == 1) b[K] = T, K++;
    }
    sort(ab, ab + I); sort(b, b + K); sort(a, a + J);
    if (J + I < k || K + I < k){
        cout << -1 << endl;
        return 0;
    }

    if(I == 0) ab[0] = INF;
    if(J == 0) a[0] = INF;
    if(K == 0) b[0] = INF;
    for(int i = 1; i < n; i++){
        if(i < J) a[i] += a[i - 1];
        else a[i] = INF;
        if(i < K) b[i] += b[i - 1];
        else b[i] = INF;
        if(i < I) ab[i] += ab[i - 1];
        else ab[i] = INF;
    }
    ulli ans = min(ab[k - 1], a[k - 1] + b[k - 1]);
    for(int i = 0; i < (k - 1); i++){
        ans = min(ans, ab[k - i - 2] + a[i] + b[i]);
    }
    cout << ans << endl;
    return 0;
}