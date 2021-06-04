# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int d[7];

int main(){
    for(int i = 0, dj; i < 3; i++) cin >> dj, d[dj]++;
    bool ok = false;
    for(int i = 1; i <= 6; i++) if(d[i] == 2 || d[i] == 3) ok = true;
    if(ok){ for(int i = 1; i <= 6; i++) if(d[i] == 1 || d[i] == 3) cout << i << endl;}
    else cout << 0 << endl;
    return 0;
}