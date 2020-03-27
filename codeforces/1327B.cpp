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
int n, k, t, e;


int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> g[n];
        for(int i = 0; i < n; i++){
            cin >> k;
            for(int j = 0; j < k; j++){
                cin >> e;
                g[i].push_back(e);
            }
        }
        bool m[n] = {false};
        int w = 100005, c = -1;
        for(int i = 0; i < n; i++){
            w = 100005;
            for(const int & el : g[i]){
                if((el - 1) <= w && m[(el - 1)] == false) w = (el - 1);
            }
            if(w != 100005){
                m[w] = true;
               
            }
            else c = i;
        }
        if(c == -1) cout << "OPTIMAL\n";
        else{
            cout << "IMPROVE\n";
            cout << c  + 1<< " ";
            for(int i = 0; i < n; i++){
                if(m[i] == false){
                    cout << i + 1 << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}