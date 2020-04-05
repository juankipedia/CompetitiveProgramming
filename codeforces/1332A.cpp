#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, d, x, y, x_1, y_1, x_2, y_2;
int main() {
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x_1 >> y_1 >> x_2 >> y_2;
        a = b - a;
        c = d - c;
        int u = x + a, v = y + c;
        if(x_1 == x_2 && (a != 0 || b != 0)) cout << "NO" << endl;
        else if(y_1 == y_2 && (c != 0 || d != 0)) cout << "NO" << endl;
        else if(u >= x_1 && u <= x_2 && v >= y_1 && v <= y_2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}