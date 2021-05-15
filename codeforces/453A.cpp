# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

long double m, n;

int main(){
    cin >> m >> n;
    long double ans = 0;
    for(long double i = 1; i <= m; i++) ans += i * (pow(i / m, n) - pow((i - 1) / m, n));
    cout << std::fixed << setprecision(6) << ans << endl;
    return 0;
}