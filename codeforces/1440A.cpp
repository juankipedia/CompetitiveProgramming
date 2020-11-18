#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int c1, c0, n, h, t;
string s;
 
int main(){
    cin >> t;
    while(t--){
        cin >> n >> c0 >> c1 >> h >> s;
        int zerocount = 0, oc = 0;
        for(int i = 0; i < n; i++)
            if(s[i] == '1') oc ++;
            else zerocount++;
        if(max(c0, c1) > h + min(c0, c1)){
            if(c0 > c1)
                cout << oc * c1 + h * zerocount + c1 * zerocount << endl;
            else{
                cout << zerocount * c0 + h * oc + c0 * oc << endl;
            }
        } 
        else cout << zerocount * c0 + oc * c1 << endl;
    }
    return 0;
}