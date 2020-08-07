#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, ms;
string s;

int main(){
    io_boost;
    cin >> t;
    ms = 1;
    while(t--){
        cin >> n;
        cin >> s;
        int ans[n];
        ms = ans[0] = 1;
        set<int> one, zero;
        if(s[0] == '0') one.insert(1);
        else zero.insert(1);
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(zero.empty()){
                    ans[i] = (*std::prev(one.end())) + 1;
                    one.insert(ans[i]);
                }
                else{
                    ans[i] = (*zero.begin());
                    zero.erase(zero.begin());
                    one.insert(ans[i]);
                }
            }
            else{
                if(one.empty()){
                    ans[i] = (*std::prev(zero.end())) + 1;
                    zero.insert(ans[i]);
                }
                else{
                    ans[i] = (*one.begin());
                    one.erase(one.begin());
                    zero.insert(ans[i]);
                }
            }
            ms = max(ms, ans[i]);
        }
        cout << ms << endl;
        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}