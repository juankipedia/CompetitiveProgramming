# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> N >> s;
        int cnt = 0;
        for(int i = 0; i < N; i++)
            if(s[i] == '0') cnt++;
        if(cnt % 2 || s[0] == '0' || s[N - 1] == '0'){
            cout << "NO" << endl;
            continue;
        }
        string a = s, b = s;
        bool open = true;
        for(int i = 1; i < N - 1; i++){
            if(s[i] == '1'){
                if(open) a[i] = b[i]  = '(';
                else a[i] = b[i] = ')';
                open = !open;
            }
        }
        open = true;
        for(int i = 1; i < N - 1; i++){
            if(s[i] == '0'){
                if(open) a[i]  = '(', b[i] = ')';
                else a[i] = ')', b[i] = ')';
                open = !open;
            }
        }
        cout << "YES" << endl << a << endl << b << endl;
    }
    return 0;
}