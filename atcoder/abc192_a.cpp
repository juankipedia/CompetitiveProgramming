#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int X;

int main(){
    cin >> X;
    int ans = 0;
    if(X % 100 == 0){
        ans++; X ++;}
    while(X % 100){
        ans++;
        X++;
    }
    cout << ans << endl;
    return 0;
}