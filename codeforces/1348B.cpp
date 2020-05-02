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

int t, n, k, b[100];

int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        set<int> s;
        for(int i = 0; i < n; i ++){
            cin >> b[i];
            s.insert(b[i]);
        }
        if(s.size() > k){
            cout << -1 << endl;
            continue;
        }
    
        if(s.size() < k){
            int len = s.size();
            for(int i = 1; i <= n; i++){
                if(s.size() == k)
                    break;
                s.insert(i);
            }
        }

        cout << n * s.size() << endl;
        for(int i =0; i < n; i++){
            for(const int &j : s)
                cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}