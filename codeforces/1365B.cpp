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

int t, n, a[500], b0, b1, b[500];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        b1 = b0 = 0;
        cin >> a[0];
        bool sorted = true;
        for(int i = 1; i < n; i++){
            cin >> a[i];
            if(a[i] < a[i - 1])
                sorted = false;
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(b[i]) b1++;
            else b0++;
        }

        if(sorted) cout << "YES" << endl;
        else if(b0 != 0 && b1 != 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}