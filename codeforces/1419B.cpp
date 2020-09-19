#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli x;

int main(){
    cin >> t;
    while(t--){
        cin >> x;

        if(x == 1){
            cout << 1 << endl;
            continue;
        }

        vector<ulli> v; v.push_back(1);
        ulli s = 1;
        ulli n = 3; 
        int j = 1;
        while ( (s + (n * (n + 1) / 2)) <= x){
            j++;
            s += (n * (n + 1) / 2);
            n = n * 2 + 1;
        }
        cout << j << endl;
    }
    //1 3 7 15 31 63 127 255 511 1023 2047 4095 8191 16383 32767 65535 131071 262143 524287 1048575 2097151 4194303 8388607 16777215 33554431 67108863 134217727 268435455 536870911 1073741823
    return 0;
}