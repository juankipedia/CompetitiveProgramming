#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string s;
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(i % 2 == 1 && (s[i] < 'A' || s[i] > 'Z')){
            cout << "No" << endl;
            //cout << i << endl;
            return 0;
        }
        if(i % 2 == 0 && (s[i] < 'a' || s[i] > 'z')){
            cout << "No" << endl;
            //cout << i << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}