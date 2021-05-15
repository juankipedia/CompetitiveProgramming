# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string s, p = "xxxx";

lli ans;


void bt(int i){
    if(i >= 4){
        set<char> ss;
        for(char e: p) ss.insert(e);
        for(int j = 0; j < 10; j++)
            if(s[j] == 'o'){
                if(!ss.count(j + '0')) return;
            }
            else if(s[j] == 'x'){
                if(ss.count(j + '0')) return;
            }

        ans++;
        return;
    }
    for(int j = 0; j <= 9; j++) p[i] = j + '0', bt(i + 1);
}

int main(){
    cin >> s;
    bt(0);
    cout << ans << endl;
    return 0;
}