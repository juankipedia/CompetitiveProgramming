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

int t, n, hn, f;

int main() {
    cin >> t;
    while(t--){
        cin >> n;
        hn = n / 2; 
        if (hn % 2 != 0){
            cout << "NO" << endl; 
            continue;
        }
        cout << "YES" << endl;
        f = 2;
        for(int i = 0; i < hn; i++)
            cout << f << " ", f += 2;
        f = 1;
        for(int i = 0; i < hn - 1; i++)
            cout << f << " ", f += 2;
        cout << f + hn << endl;
    }
    return 0;
}