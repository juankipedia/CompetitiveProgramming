#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
int main(){
    cin >> t;
    while (t--){
        lli n, x, ai;
        cin >> n >> x;
        lli s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++){
            cin >> ai;
            s1 += ai;
            s2 += (ai + x - 1)/ x;
        }
        cout << (s1 + x - 1) / x << " " << s2 << endl;
    }
    
    return 0;
}