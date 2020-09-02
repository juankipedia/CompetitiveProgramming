#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
lli a[100000];

int main(){
    io_boost;
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];

    if(n == 1){
        cout << 1 << " " << 1 << endl;
        cout << a[0] * -1 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
    }
    else{
        cout << "1 1" << endl;
        cout << a[0] * -1 << endl;
        cout << 1 << " " << n << endl;
        cout << 0 << " ";
        for(int i = 1; i < n; i++) cout << a[i] * -n << " ";
        cout << endl;
        cout << 2 << " " << n << endl;
        for(int i = 1; i < n; i++) cout << (n - 1) * a[i] << " ";
        cout << endl;
    } 
    return 0;
}