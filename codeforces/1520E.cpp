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
        lli l = 0, lc = 0, r = 0, rc = 0;
        int p = 0;
        if(s[0] == '*') p = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == '*'){
                r++;
                rc += i - p;
                p++;
            }    
        }

        lli ans = rc + lc;
        for(int i = 1; i < n; i++){
            if(s[i - 1] == '*') l++;
            if(s[i] == '.'){
                lc += l;
                rc -= r;
            }
            else{
                if(l == 0) rc -= r;
                r--;
            }
            //cout << lc + rc << endl;
            ans = min(lc + rc, ans);
        }

        cout << ans << endl;

    }
    return 0;
}