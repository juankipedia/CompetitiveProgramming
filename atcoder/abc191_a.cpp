#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int v, t, s, d;

int main(){
    cin >> v >> t >> s >> d;
    int e1 = v * t, e2 = v * s;
    if(d < e1 || d > e2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}