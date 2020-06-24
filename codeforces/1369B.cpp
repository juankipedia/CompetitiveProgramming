#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;
 
int t, n;
string s;
 
int main() {
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        string ans = "";
        int ii = 0;
        while(ii < n && s[ii] == '0'){
            ans += s[ii];
            ii++;
        }
        int i = ii;
        while(i < n){
            string ones = "";
            int j = i;
            while(j < n && s[j] == '1') j++;
 
            if(j >= n) break;
            else
                while(j < n && s[j] == '0') j++;
            i = j;
        }
        if(i != ii) ans += '0';
        for(; i < n; i++) ans += s[i];
        cout << ans << endl;
    }
    return 0;   
}
