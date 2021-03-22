# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(a, b) - min(c, d) << endl;
    return 0;
}