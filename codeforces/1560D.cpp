//fi + 1 = 2 * i  -  1 + fi;
 
 
# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/
 
 
string n;
 
 
int main(){
    io_boost;
    int t;
    cin >> t;
 
    while(t--){
        cin >> n;
        int ans = 1e9;
        for(ulli k = 0; k <= 65; k++){
            ulli p = (1ULL << k);
            string ps = to_string(p);
            int d = 0, i = 0, j = 0, ns = n.size(), pss = ps.size();
            while(i < ns && j < pss){
                if(n[i] != ps[j]) d++, i++;
                else j++, i++;
            }
            
            ans = min(ans, abs(ns - d - pss) + d);
        }
        cout << ans << endl;
    }
    return 0;
}