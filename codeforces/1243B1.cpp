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

int k, n;
string s, t;
char cs, ct;

int main() {
    cin >> k;
    while(k --){
        cin >> n;
        cin >> s >> t;
        cs = ct = '|';
        bool f = false;
        for(int i = 0; i < n; i++){
            
            if(s[i] != t[i] and cs == '|'){

                cs = s[i];
                ct = t[i];
            }
            else if(s[i] != t[i] and cs != '|' and not f){
                if(cs == s[i] and ct == t[i]) f = true;
                else{
                    f = false;
                    break;
                }
            }
            else if(s[i] != t[i] and f){
                f = false;
                break;
            }
        }
        if(f) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}