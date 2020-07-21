#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, c;
lli a[100000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        c = 0;
        while(a[c] == 1 and c != (n - 1))c++;
        if(c % 2) cout << "Second" << endl;
        else cout << "First" << endl;
    }
    return 0;
}