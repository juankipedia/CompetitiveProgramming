#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int a, x, y;
 
int main(){
    cin >> a >> x >> y;
    if(y == 0 || y == a){ cout << -1 << endl; return 0; }
    if(y < a){ 
        if(a % 2 && abs(x) <= a / 2) cout << 1 << endl;
        else if(a % 2 == 0 && abs(x) < a / 2) cout << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }
    y -= a;
    if(y % a == 0){ cout << -1 << endl; return 0;}
    int yp = (y + a - 1) / a;
    if(yp % 2){
        int s = (yp / 2) + yp + 1;
        if(a % 2 && abs(x) <= a / 2) cout << s << endl;
        else if(a % 2 == 0 && abs(x) < a / 2) cout << s << endl;
        else cout << -1 << endl; 
    }
    else{
        int s = (yp / 2) - 1 + yp + 1 + (x > 0 ? 1 : 0);
        if(x == 0 || abs(x) >= a) cout << -1 << endl;
        else cout << s << endl;
 
    }
    return 0;
}