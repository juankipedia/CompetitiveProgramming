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

ulli t, n, r, a[30], p1, p2;

int main() {
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 2) cout << 2 << endl;
        else{
            for(ulli i = 1; i <= n; i ++)
                a[i - 1] = (1 << i);
            vector<ulli> m, M;
            for(ulli i = 0; i < n / 2; i ++)
                m.push_back(a[i]);
            for(ulli i = n / 2; i < n; i ++)
                M.push_back(a[i]);
            
            swap(M[n / 2 - 1], m[n / 2 - 1]);

            p1 = 0; p2 = 0;
            for(ulli i = 0; i < n / 2; i ++){
                p1 += m[i];
                p2 += M[i];
            }
                

            //cout << p1 << " " << p2 << endl;
            cout << p1 - p2 << endl;
        }
    }
    return 0;
}