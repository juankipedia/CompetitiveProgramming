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
const ulli ONE = 1;
ulli p;
int t, x, n, m, h;

int main() {
    cin >> t;
    while(t--){
        cin >> x >> n >> m;
        int x2 = x;
        for(int i = 0; i < n; i++)
            x = x/2 + 10;
        x -= 10 * m;
        if(x <= 0) cout << "YES" << endl;
        else{
            x2 -= 10 * m;
            if(x2<=0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}