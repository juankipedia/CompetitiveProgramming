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
    for(int i = 1; i < s.size(); i++) cout << s[i];
    cout << s[0] << endl;
    return 0;
}