#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli a, b, x, y, n;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> a >> b >> x >> y >> n;
        ulli maxia = (a - x);
        ulli maxib = (b - y);

        ulli minib = min(n, maxib);
        ulli minia = min(n, maxia);

        ulli ans = (a - min(maxia, n - minib)) * (b - minib);
        //cout << ans << endl;
        ans = min(ans, (b - min(maxib, n - minia)) * (a - minia));
        //cout << ans << endl;
        ulli n1 = n / 2;
        ulli n2 = n - n1;
        ans = min(ans, (a - min(n2, maxia)) * (b - min(n1, maxib)));
        //cout << ans << endl;
        ans = min(ans, (a - min(n1, maxia)) * (b - min(n2, maxib)));
        //cout << ans << endl;
        cout << ans << endl;
    }
    return 0;
}