#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string n;
int k;

int main(){
    cin >> n >> k;
    int c = 0, ans = 0;
    for(int i = n.size() - 1; i >= 0; i--){
        if(n[i] == '0') c++;
        else ans++;
        if(c == k){
            cout << ans << endl;
            return 0;
        }
    }
    cout << n.size() - 1 << endl;
    return 0;
}