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

int t, n, k, r, L, R, ra[200000];
lli a[200000];
bool p[200000];
int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 1; i < n - 1; i++)
            if(a[i] > a[i - 1] && a[i] > a[i + 1]) p[i] = true;
            else p[i] = false;
        p[0] = p[n - 1] = false;
        
        r = 0;
        L = 0, R = k - 1;
        for(int i = 1; i < k - 1; i++)
            if(p[i]) r++;
        ra[L] = r;
        L++; R++;
        for(; R < n; L++, R++){
            if(p[L]) r--;
            if(p[R - 1]) r++;
            ra[L] = r;
        }
        r = 0;
        for(int i = 0; (i + k - 1) < n; i++)
            r = max(ra[i], r);
        for(int i = 0; (i + k - 1) < n; i++){
            if(ra[i] == r){
                cout << r + 1 << " " << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}