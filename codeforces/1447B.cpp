#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m, ai, mini, c, s;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        mini = 100000;
        c = 0;
        s = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> ai;
                if(ai <= 0) c++;
                mini = min(abs(ai), mini);
                s += abs(ai);
            }
        }
        if(c % 2) cout << s - mini * 2 << endl;
        else cout << s << endl;
    }
    return 0;
}