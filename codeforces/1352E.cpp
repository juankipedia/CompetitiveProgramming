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

int n, t, a[8000], s[8001], m[8001], c, ss;
bool tt[8001];

int main() {
    cin >> t;
    while(t --){
        cin >> n;
        cin >> a[0];
        s[0] = 0;
        s[1] = a[0];
        for(int i = 0; i <= n; i++){
            tt[i] = false;
            m[i] = 0;
        }
        m[a[0]] = 1;
        for(int i = 1; i < n; i++){
            cin >> a[i];
            s[i + 1] = s[i] + a[i];
            m[a[i]]++;
        }
        c = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                ss = s[j] - s[i - 1];
                if(ss <= n && !tt[ss]){
                    c += m[ss];
                    tt[ss] = true;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}