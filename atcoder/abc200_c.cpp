# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, A[200005];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    int m[200] = {0};
    lli ans = 0;
    for(int i = 0; i < N; i++) ans += m[A[i] % 200], m[A[i] % 200]++;
    cout << ans << endl;
    return 0;
}