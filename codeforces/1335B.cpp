#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;


int t, n, a, b;

int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        for(int i = 0; i < n; i++){
            cout << (char)((i % b) + 'a');
        }
        cout << endl;
    }
    return 0;
}