#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int a, b, k;
 
int main(){
    cin >> a >> b >> k;
    string x = "", y = "";
    for(int i = 0; i < b; i++) x += "1", y += "1";
    for(int i = 0; i < a; i++) x += "0", y += "0";
    int n = x.size();
    if(b == 1 && k != 0){
        cout << "No" << endl;
        return 0;
    }
    else if(b == 1){
        cout << "Yes" << endl;
        cout << x << endl;
        cout << y << endl;
        return 0;
    }
    if((a + b - 2) < k) cout << "No" << endl;
    else if(a == 0 && k != 0) cout << "No" << endl;
    else if(k == 0){
        cout << "Yes" << endl;
        cout << x << endl;
        cout << y << endl;
        return 0;
    }
    else{
        y[n - 1] = '1';
        if((n - k - 1) <= b - 1) y[n - k - 1] = '0';
        else{
            x[b - 1] = '0';
            y[b - 1] = '0';
            x[n - k - 1] = '1';
        }
        cout << "Yes" << endl;
        cout << x << endl;
        cout << y << endl;
        return 0;
    }
    return 0;
}