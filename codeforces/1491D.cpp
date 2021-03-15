# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, u, v;

int main(){
    cin >> t;
    while(t--){
        cin >> u >> v;
        int c = 0;
        bool yes = true;
        if(u > v) yes = false;
        for(int i = 0; i <= 30; i++){
            if(u & (1 << i)) c++;
            if(v & (1 << i)) c--;
            if(c < 0) yes = false;
        }
        if(yes) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}