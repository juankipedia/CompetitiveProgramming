# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string s;

int main(){
    cin >> s;
    int i = 0;
    while(i < s.size() && s[i] != '.') cout << s[i], i++;
    cout << endl;
    return 0;
}