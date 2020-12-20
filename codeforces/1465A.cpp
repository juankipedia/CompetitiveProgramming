#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        int cnt = 0;
        int i = n - 1;
        for(; i >= 0; i--)
            if(s[i] == ')') cnt++;
            else break;
        if(i + 1 >= cnt) cout << "No" << endl;
        else cout << "Yes" << endl;

    }
    return 0;
}