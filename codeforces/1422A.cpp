#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t;
 
lli abc[3], d;
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> abc[0] >> abc[1] >> abc[2];
        sort(abc, abc + 3);
        cout << abc[2] + 1 << endl;
    }
    return 0;
}