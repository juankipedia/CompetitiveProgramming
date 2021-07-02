# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int c[3];

int main(){
    cin >> c[0] >> c[1] >> c[2];
    sort(c, c + 3);
    cout << c[2] + c[1] << endl;
    return 0;
}