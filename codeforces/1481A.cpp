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
        lli px, py, x = 0, y = 0;
        cin >> px >> py;
        cin >> s;
        map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'U') y++;
            if(s[i] == 'D') y--;
            if(s[i] == 'R') x++;
            if(s[i] == 'L') x--;
            m[s[i]]++;
        }
        if(x == px && y == py) cout << "YES" << endl;
        else{
            bool ok = true;
            //cout << "====" << m['L'] << " " << abs(px - x) << endl;
            if(x > px && m['R'] < abs(x - px)) ok = false;
            else if(x < px && m['L'] < abs(px - x)) ok = false;

            if(y > py && m['U'] < abs(y - py)) ok = false;
            else if(y < py && m['D'] < abs(py - y)) ok = false;

            if(ok) cout << "YES" << endl;
            else cout << "NO" << endl;

        }
    }
    
    return 0;
}