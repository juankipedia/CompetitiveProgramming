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
const int INF = 100000000;
int t, fz, fo, lo;
string s;

int main() {
    cin >> t;
    while(t--){
        cin >> s;
        int n = s.size();
        int ans = INF;
        int z = 0, o = 0;
        for(int i = 0; i < n; i++)
            if(s[i] == '0') z++;
            else o ++;

        int zi = 0, oi = 0, zt = z, ot= o;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){zi++; zt--;}
            else{oi++; ot--;}
            ans = min(min(oi + zt, zi + ot), ans);
        }
        cout << min(ans, min(z, o)) << endl;
    }
    return 0;
}