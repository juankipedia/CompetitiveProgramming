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
string a, b, c;

int main() {
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        n = a.size();
        bool f = false;
        for(int i = 0; i < n; i++){
            if(c[i] == b[i]) continue;
            else if(c[i] == a[i]) continue;
            else{ f = true; break;}
        }
        if(!f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}