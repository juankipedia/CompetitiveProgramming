
# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli A, B, C, D;

int main(){
    cin >> A >> B >> C >> D;
    lli ans = 0;
    for(int i = 1; i < 999; i++){
        for(int j = 1; i + j <= 999; j++){
            if(std::gcd(i,j) > 1) continue;
            if(i > B || j > D) continue;
            lli a = (A - 1) / i + 1, b = B / i, c = (C - 1) / j + 1, d = D / j;
            a = max(a, c);
            b = min(b, d);
            ans += max(0ll, b - a + 1);
        }
    }
    cout << ans << endl;
    return 0;
}