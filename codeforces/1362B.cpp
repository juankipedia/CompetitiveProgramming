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

int t, n, S[1024];
bool ms[1025];

int main() {
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < 1025; i++) ms[i] = false;
        for(int i = 0; i < n; i++) cin >> S[i], ms[S[i]] = true;
        bool ok = false;
        for(int k = 1; k < 1024; k++){
            bool mss[1025] = {false};
            bool f = true;
            for(int i = 0; i < n; i++){
                int ns = S[i] ^ k;
                if(ms[ns] && !mss[ns])
                    mss[ns] = true;
                else{
                    f = false;
                    break;
                }
            }
            if(f){
                cout << k << endl;
                ok = true;
                break;
            }
        }
        if(!ok)
            cout << -1 << endl;
    }
    return 0;
}