# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int main(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for(char c: s){
        if(c == '6') cout << '9';
        else if(c == '9') cout << '6';
        else cout << c;
    }
    cout << endl;
    return 0;
}