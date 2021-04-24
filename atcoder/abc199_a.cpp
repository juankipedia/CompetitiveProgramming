# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int A, B, C;

int main(){
    cin >> A >> B >> C;
    if((A * A + B * B) < C * C) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}