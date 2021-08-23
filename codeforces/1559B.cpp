# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, n;
string s;

int check(int l, int r, bool b){
    string w = s;
    for(int i = l + 1; i < r; i++){
        if(b) w[i] = 'B';
        else w[i] = 'R';
        b = !b;
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) if(w[i] == w[i + 1]) ans++;
    return ans;
}

void sets(int l, int r, bool b){
    for(int i = l + 1; i < r; i++){
        if(b) s[i] = 'B';
        else s[i] = 'R';
        b = !b;
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        s = "#" + s + "#";
        for(int i = 1; i <= n; i++){
            if(s[i] == '?'){
                int j = i;
                while(j <= n && s[j] == '?') j++; 
                i--;
                if(check(i, j, true) < check(i, j, false)) sets(i, j, true);
                else sets(i, j, false);
            }
        }
        for(int i = 1; i <= n; i++) cout << s[i];
        cout << endl;
    }
    return 0;
}