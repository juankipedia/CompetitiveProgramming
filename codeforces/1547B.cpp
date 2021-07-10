# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;

int main(){
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        int n = s.size();
        bool ok  = true;
        int l = 0, r = n - 1;
        for(int i = n - 1; i >= 0; i--){
            if((s[l] == s[r] && l != r) || max(s[l] - 'a', s[r] - 'a') != i){
                ok = false;
                break;
            }
            if(s[l] > s[r]) l++;
            else r--;
        }
        if(ok) cout << "YES" << endl;
        else cout <<"NO" << endl;
    }   
    return 0;
}