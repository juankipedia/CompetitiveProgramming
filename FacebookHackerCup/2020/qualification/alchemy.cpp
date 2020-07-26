#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, ti, n;
string s;

bool f(){
    int c[2] = {0};
    for(int i = 0; i < n; i++)
        c[s[i] - 'A'] ++; 
    return (abs(c[0] - c[1]) == 1);
    
}

int main(){
    io_boost;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> n >> s;
        cout << "Case #" << ti << ": ";
        if(f()) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}