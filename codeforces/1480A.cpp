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
    while(t--){
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); i++)
            if(i % 2 == 0  && s[i] != 'a') cout << 'a';
            else if(i % 2 == 0 && s[i] == 'a') cout << 'b';
            else if(i % 2 && s[i] != 'z') cout << 'z';
            else if(i % 2 && s[i] =='z') cout << 'y';
        cout << endl; 
    }
    
    return 0;
}