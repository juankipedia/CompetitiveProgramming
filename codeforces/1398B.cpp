#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
string s;

int main(){
    cin >> t;
    while (t--){
       vector<int> v;
       cin >> s;
       int ac = 0;
       for(int i = 0; i < s.size(); i++){
           if(s[i] == '0'){
               if(ac) v.push_back(ac);
               ac = 0;
           }
           else ac++;
       }
       if(ac) v.push_back(ac);
       sort(v.begin(), v.end(), std::greater<int>());
       int ans = 0;
       for(int i = 0; i < v.size(); i++)
            if(i % 2 == 0) ans += v[i];
        cout << ans << endl;
    }
    
    return 0;
}