#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
int main() {
    int y, b, r;
    cin >> y >> b >> r;

    if(r > b) r = b + 1;
    else if(r == b) b = b - 1;
    else if(r < b) b = r - 1;
    
    if(b > y){
        b = y + 1;
        r = b + 1;
    }
    if(b == y) y --;
    else if(b < y) y = b - 1;
    
    cout << y + b + r << endl;
    return 0;
}