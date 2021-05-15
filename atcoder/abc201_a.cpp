# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int a[3];

int main(){
    cin >> a[0] >> a[1] >> a[2];
    if(2 * a[1] == a[2] + a[0]) cout << "Yes" << endl;
    else if(2 * a[0] == a[2] + a[1]) cout << "Yes" << endl;
        else if(2 * a[2] == a[0] + a[1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    return 0;
}