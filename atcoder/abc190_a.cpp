#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int a, b, c;

int main(){
    cin >> a >> b >> c;
    bool t = true;
    while(true){
        if(a == 0 && c == 0){
            t = false;
            break;
        }
        if(b == 0 && c == 1){
            t = true;
            break;
        }
        if(!c) a--;

        if(c) b--;

        if(c) c = 0;
        else c = 1;
    }
    if(t) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}