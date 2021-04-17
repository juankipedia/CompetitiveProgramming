# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        string s;
        cin >> s;
        queue<int> ts, te;
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(s[i] == 'T') ts.push(i);
            else{
                if(ts.empty()) ok = false;
                else{
                    s[ts.front()] = 'X';
                    ts.pop();
                }
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'T') te.push(i);
            else if(s[i] == 'M'){
                if(te.empty()) ok = false;
                else te.pop();
            }
        }
        if(!ok || !te.empty()) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}