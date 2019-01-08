# include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, r;
    cin >> x >> y;
    r = x / y;
    if((x % y == 0) or static_cast<long long>(x) * y < 0);
    else r += 1;
    cout << r << endl;
}