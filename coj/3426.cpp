#include <bits/stdc++.h>
using namespace std;

int main() {
    long long unsigned int a, b;
    cin >> a >> b;
    if(a >= b) cout << (2 * b - 1) * a << endl;
    else cout << (2 * a - 1) * b << endl; 

    return 0;
}