#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N;

int main(){
    cin >> t;
    while(t--){
        cin >> N;
        int e = (N + 4 - 1) / 4;
        int n = N - e;
        cout << string(n, '9') << string(e, '8') << endl;
    }
    return 0;
}