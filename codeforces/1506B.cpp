# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
lli t, n, k;
string s;
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        int l = 0, r = n - 1;
        while(s[l] != '*') l++;
        while(s[r] != '*') r--;
        int ans = 0;
        if(r == l){
            cout << 1 << endl;
            continue;
        }
        ans = 2;
        //cout << l << " " << r << endl;
        for(int i = l; i < r;){
            int j = i + 1, ki = 0;
            for(; j < r && ki < k; ki++, j++){
                if(s[j] == '*') i = j;
            }
            if(j == r){
                if(ki == k) ans++;
                break;
            }
            else ans++;
            //cout << "fsdfasdfs " << i  << endl;
        }
        cout << ans << endl;
    }
    return 0;
}