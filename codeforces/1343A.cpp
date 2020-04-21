#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;


int t;
ulli n;

int main() {
    cin >> t;
    while(t--){
        cin >> n;
        ulli k = 2;
        ulli p = (1 << k) - 1;
        while((n % p) != 0){
            k ++;
            p = (1 << k) - 1;
           
        }
        cout << n / p << endl;
    }
    return 0;
}