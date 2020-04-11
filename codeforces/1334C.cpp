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
ulli a[300000], b[300000], s, mini;

int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
        }
        if(a[0] > b[n - 1]){
            s = a[0] - b[n - 1];
            a[0] = b[n - 1];
        
        }
        else s = 0;
        mini = a[0];
        for(int i = 1; i < n; i++){
            if(a[i] > b[i - 1]){
                s += a[i] - b[i - 1];
                a[i] = b[i - 1];
            }
            mini = min(a[i], mini);
        }
        cout << s + mini << endl;
    }
    return 0;
}