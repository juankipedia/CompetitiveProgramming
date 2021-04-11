# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, a, b;
string s;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> a >> b >> s;
        int n = a + b;
        int i = 0, j = n - 1;
        while(i < j){
            if(s[i] == '?' && s[j] != '?'){
                if(s[j] == '1'){
                    b-=2;
                    s[i] = '1';
                }
                else{
                    a-=2;
                    s[i] = '0';
                }
            }
            else if(s[i] != '?' && s[j] == '?'){
                if(s[i] == '1'){
                    b-=2;
                    s[j] = '1';
                }
                else{
                    a-=2;
                    s[j] = '0';
                }
            }
            else if(s[i] != s[j]){
                a = b = -1;
                break;
            }
            else if(s[i] != '?'){
                if(s[i] == '0') a-=2;
                else b-=2;
            }
            i++;
            j--;

        }

        if(a < 0 || b < 0){
            cout << -1 << endl;
            continue;
        }

        i = 0; j = n - 1;
        while(i < j){
            if(s[i] == s[j] && s[i] == '?'){
                if(a > b){
                    s[i] = s[j] = '0';
                    a -= 2;
                }
                else{
                    s[i] = s[j] = '1';
                    b -= 2;
                }
            }
            i++;
            j--;
        }
        //cout << a << " " << b << endl;
        if(i == j && s[i] == '?'){
            if(a > b){
                s[i] = '0';
                a--;
            }
            else{
                s[i] = '1';
                b--;
            }
        }
        else if(i == j){
            if(s[i] == '1') b--;
            else a--;
        }

        if(a == 0 && b == 0){
            cout << s << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}