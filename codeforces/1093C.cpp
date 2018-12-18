#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int ulli;
typedef long long int lli;


int main() {
    ulli n;
    cin >> n;
    while(true){
        ulli x = 0; 
        bool f = false;
        for (ulli i = n; i >= 1; i--){
            if(n % i != 0){
                x = i;
                f = true;
                break;
            }
        }

        n -= x;

        if(not f)
            break;
    }
    cout << n << endl;
    return 0;
}