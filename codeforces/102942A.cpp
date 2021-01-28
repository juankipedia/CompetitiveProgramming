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
        int n;
        cin >> n;
        string s;
        cin >> s;
        char in = 'E';
        for(int i = 0; i < n; i++){
            if(in == 'E' && s[i] == '0') in = 'S';
            else if(in == 'E' && s[i] == '1') in = 'N';
            else if(in == 'S' && s[i] == '0') in = 'W';
            else if(in == 'S' && s[i] == '1') in = 'E';
            else  if(in == 'W' && s[i] == '0') in = 'N';
            else if(in == 'W' && s[i] == '1') in = 'S';
            else  if(in == 'N' && s[i] == '0') in = 'E';
            else if (in == 'N' && s[i] == '1') in = 'W';

        }
        cout << in << endl;
    }
    
    return 0;
}