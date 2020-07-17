#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string s;

int f(int l, int r, int i){
    if(l == r){
        if(s[l] == 'a' + i) return 0;
        else return 1;
    }
    int c1 = 0, c2 = 0, mid = (r - l) / 2;
    for(int j = l; j <= (l + mid); j++) 
        if(s[j] != ('a' + i))
            c1 ++;
    for(int j = l + mid + 1; j <= r; j++) 
        if(s[j] != ('a' + i))
            c2 ++;
            
    return min(c1 + f(l + mid + 1, r, i + 1), c2 + f(l, l + mid, i + 1));
    
}

int main(){
    io_boost;
    cin >> t;
    while (t--){
        cin >> n;
        cin >> s;
        cout << f(0, n - 1, 0) << endl;
    }
    
    return 0;
}