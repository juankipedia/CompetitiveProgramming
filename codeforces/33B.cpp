#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli oo = numeric_limits<int>::max();
lli g[26][26], n, u, v, w;
string s, t, a;


int main(){
    cin >> s >> t;
    cin >> n;

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            if(i != j) g[i][j] = oo;
            else g[i][j] = 0;

    while (n--){
        cin >> a;
        u = a[0] - 'a';
        cin >> a;
        v = a[0] - 'a';
        cin >> w;
        g[u][v] = min(g[u][v], w);
    }

    if(s.size() != t.size()){
        cout << -1 << endl;
        return 0;
    }
    for(int k = 0; k < 26; k++)
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    
    lli ans = 0;
    string ss = "";
    for(int i = 0; i < s.size(); i++){
        lli min_cost = oo, c = -1;
        for(int j = 0; j < 26; j++){
            if(min_cost > (g[s[i] - 'a'][j] + g[t[i] - 'a'][j])){
                min_cost = g[s[i] - 'a'][j] + g[t[i] - 'a'][j];
                c = j;
            }
        }
        if(c == -1){
            cout << -1 << endl;
            return 0;
        }
        ss += (c + 'a');
        ans += min_cost;
    }   
    cout << ans << endl;
    cout << ss << endl;
    return 0;
}