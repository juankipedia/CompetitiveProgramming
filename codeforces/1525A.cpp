# include <bits/stdc++.h>
using namespace std;

int main(){
    int t, k;
    cin >> t;
    while(t--){
        cin >> k;
        int m = 1;
        while(100 * m % k != 0) m++;
        cout << 100 * m / k << endl;
    }
    return 0;
}