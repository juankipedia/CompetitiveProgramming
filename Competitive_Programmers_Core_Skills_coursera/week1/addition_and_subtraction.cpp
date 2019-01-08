#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int x, y, z;
    cin >> x >> y >> z;
    int r = -1;
    int a_e = 0, a_o = 0;
    r ++;
    if(z == 0){cout << 0 << endl; return 0;}
    if(x == y){
        if(z == x){cout << "1\n";return 0;} 
        else{cout << "-1\n";return 0;}
    }
    while(a_e < z or a_o < z){
    	a_o = a_e + x;
    	r ++;
    	if(a_e == z or a_o == z){cout << r << endl; return 0;}
    	a_e = a_o - y;
    	r ++;
    	if(a_e == z or a_o == z){cout << r << endl; return 0;}
    }
    cout << -1 << endl;
    return 0;
}