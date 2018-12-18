#include <bits/stdc++.h>
using namespace std;



int main() {
    unsigned int t, x;
    cin >> t;
    while(t--){
        cin >> x;
        unsigned int count = 0;
        while(x != 0){
            count = x / 7;
            x -= (7 * (x / 7));

            if(x <= 7 and x > 0){
                count ++;
                break;
            }
        }

        cout << count << endl;
    }
    return 0;
}