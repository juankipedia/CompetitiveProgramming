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
 
int t, k;
lli n;
 
int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n % 2 == 0 && k % 2 != 0){
            if(n / 2 < k){cout << "NO" << endl; continue;}
            cout << "YES" << endl;
            for(int i = 0; i < k - 1; i++)
                cout << 2 << " ";
            cout << (n / 2 - k + 1) * 2 << endl;
            
        }
        else if(n % 2 != 0 && k % 2 != 0 || n % 2 == 0 && k % 2 == 0){
            if(n < k){cout << "NO" << endl; continue;}
            cout << "YES" << endl;
            for(int i = 0; i < k - 1; i++)
                cout << 1 << " ";
            cout << n - k + 1 << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
