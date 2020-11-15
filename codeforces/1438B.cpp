#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli b[1000];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        set<lli> sb;
        for(int i = 0; i < n; i++) cin >> b[i];
        bool f = false;
        for(int i = 0; i < n; i++){
            if(sb.find(b[i]) != sb.end()){
                f = true;
                break;
            }
            else sb.insert(b[i]);
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}