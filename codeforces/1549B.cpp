# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int t;

int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string e, g;
        cin >> e >> g;
        int ans = 0;
        if(g[0] == '1'){
            if(e[0] == '0') ans++, e[0] = '2';
            else if(e[1] == '1') ans ++, e[1] = '2';
        }
        for(int i = 1; i < n - 1; i++)
            if(g[i] == '1'){
                if(e[i] == '0')
                    e[i] = '2',
                    ans++;
                else if(e[i - 1] == '1') e[i - 1] = '2',
                ans ++;
                else if(e[i + 1] == '1') e[i + 1] = '2',
                ans++;
            }
            
        if(g[n - 1] == '1'){
            if(e[n - 1] == '0') ans++;
            else if(e[n - 2] == '1') ans ++;
        }
        
        cout << ans << endl;
    }
    return 0;
}