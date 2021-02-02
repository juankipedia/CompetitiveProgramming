#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t;
string a, b;
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> a >> b;
        map<char, int> m;
        for(int i = 0; i < b.size(); i++)
            m[b[i]]++;
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            if(m.count(a[i]) && m[a[i]]){
                m[a[i]]--;
                ans++;
            }
            else break;
        }
        cout << ans << endl;
    }
    
    return 0;
}