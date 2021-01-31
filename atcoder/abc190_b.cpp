#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, s , d;

int main(){
    cin >> n >> s >> d;
    bool ok = false;
    for(int i = 0; i < n; i++){
        int xi, yi;
        cin >> xi >> yi;
        if(xi < s && yi > d) ok = true;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}