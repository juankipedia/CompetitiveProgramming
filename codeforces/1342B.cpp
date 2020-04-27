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

int T, p;
string t; 

int main() {
    io_boost;
    cin >> T;
    while(T--){
        cin >> t;
        p = 1;
        for(int i = 1; i < t.size(); i++){
            if(t[i] != t[i - 1]){
                p = 2; break;
            }
        }
        if(p == 1) cout << t << endl;
        else{
            cout << t[0];
            for(int i = 1; i < t.size(); i++){
                if(t[i] == t[i - 1]){
                    if(t[i - 1] == '1') cout << 0;
                    else cout << 1;
                    cout << t[i];
                }
                else cout << t[i];
            }
            cout << endl;
        }
        
    }
    return 0;
}