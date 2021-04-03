# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string n;

int main(){
    cin >> n;
    while(true){
        int ans = 0;
        for(char c: n) ans += c - '0';
        n = to_string(ans);
        if(n.size() == 1){
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}