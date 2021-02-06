#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, x;

int main(){
    cin >> n >> x;
    lli a[n];
    for(int i = 0;i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++)
        if(a[i] != x) cout << a[i] << " ";
    cout << endl;
    return 0;
}