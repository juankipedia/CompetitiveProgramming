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
 
int main(){
    cin >> t;
    int c = 1;
    while(t--){
        cin >> n >> s;
        s="#"+s;
        // if(c == 123) cout << s << endl;
        // c++;
        int d = -1;
        for(int i = n / 2 + 1; i <= n; i++)
            if(s[i] == '0'){
                d = i;
                break;
            }
        if(d != -1) cout << 1 << " " << d << " " << 1 << " "  << d-1 << endl;
        else if(s[n / 2] == '0') cout << n / 2 << " " << n << " " << n / 2 +1<< " " << n << endl;
        else cout << n / 2<< " " << n - 1 << " " << n / 2+1 << " " << n << endl;
    }
    return 0;
}