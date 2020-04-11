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

int t, ti, n, r, k, s, i;

int main() {
    io_boost;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> n;
        r = k = 1;
        s = 1;
        cout << "Case #" << ti << ":\n" << r <<  " " << k << endl;
        if(n == 1) continue;
        r = k = 2;
        s = 2;
        cout << r <<  " " << k << endl;
        if(n == 2) continue;
        i = 2;
        while(s != n){
            if(s + 1 == n){
                k--;
                s++;
                cout << r <<  " " << k << endl;
            }
            else{
                r++;
                s+=i;
                //cout << s << " " << r << endl;
                if(s > n) break;
                i++;
                cout << r <<  " " << k << endl;
            }
        }
        if(s == n) continue;
        r--; k--; s -= i;
        s++;
        cout << r << " " << k << endl;
        for(int j = 0; j < n - s; j++){
            r ++;
            cout << r << " " << k << endl;
        }
    }
    return 0;
}