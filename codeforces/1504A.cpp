# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
string s;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> s;
        string sb = "a" + s;
        string se = s + "a";
        int i = 0, j = sb.size() - 1;
        bool ok = true;
        while(i <= j){
            if(sb[i] != sb[j]){
                ok = false;
                break;
            }
            i++; j--;
        }
        if(!ok){
            cout << "YES" << endl;
            cout << sb << endl;
            continue;
        }

        i = 0; j = se.size() - 1;
        ok = true;
        while(i <= j){
            if(se[i] != se[j]){
                ok = false;
                break;
            }
            i++; j--;
        }
        if(!ok){
            cout << "YES" << endl;
            cout << se << endl;
            continue;
        }

        cout << "NO" << endl;
    }
    return 0;
}
