#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n;
string b;
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> b;
        string a = string(n, '0'), d;
        d = a;
        //cout << a << endl;
        a[0] = '1';
 
        if(a[0] == '1' && b[0] == '1') d[0] = '2';
        else if(a[0] == '0' && b[0] == '1') d[0] = '1';
        else if(a[0] == '1' && b[0] == '0') d[0] = '1';
        else d[0] = '0';
 
        for(int i = 1; i < n; i++){
            a[i] = '1';
            if(a[i] == '1' && b[i] == '1') d[i] = '2';
            else if(a[i] == '0' && b[i] == '1') d[i] = '1';
            else if(a[i] == '1' && b[i] == '0') d[i] = '1';
            else d[i] = '0';
 
            if(d[i] == d[i - 1]){
                a[i] = '0';
 
                if(a[i] == '1' && b[i] == '1') d[i] = '2';
            else if(a[i] == '0' && b[i] == '1') d[i] = '1';
            else if(a[i] == '1' && b[i] == '0') d[i] = '1';
            else d[i] = '0';
            
            }
        }       
        cout << a << endl;
 
    }
    return 0;
}
