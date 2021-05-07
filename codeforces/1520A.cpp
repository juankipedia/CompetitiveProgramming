# include <bits/stdc++.h>
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
        cin >> n >> s;
        set<char> tasks;
        tasks.insert(s[0]);
        bool ok = true;
        for(int i = 1; i < n; i++)
            if(s[i] != s[i - 1]){
                if(tasks.count(s[i])){
                    ok = false;
                    break;
                }
                else tasks.insert(s[i]);
            }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}