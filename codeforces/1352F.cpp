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


int n0, n1, n2, t;

int main() {
    cin >> t;
    while(t--){
        cin >> n0 >> n1 >> n2;
        if(n2) for(int i = 0; i <= n2; i++) cout << "1";
        if(n0) for(int i = 0; i <= n0; i++) cout << "0";
        if(!n0 && n1){cout << "0"; n0++;};
        if(n1){
            if(n2 && n0) n1--;
            for(int i = 0; i < n1; i++)
                if(i % 2 == 0) cout << "1";
                else cout << "0";
        }
        cout << endl;
    }
    return 0;
}