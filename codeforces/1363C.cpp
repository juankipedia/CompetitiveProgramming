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
const int INF = numeric_limits<int>::max();
int t, n, x, u, v, a;
bool jt;

int main() {
    cin >> t;
    while(t--){
        cin >> n >> x;
        a = 0;
        for(int i = 0; i < n - 1; i++){
            cin >> u >> v;
            if(u == x || v == x) a++;
        }
        if(a <= 1)
            cout << "Ayush" << endl;
        else{
            jt = (n - (a + 1)) % 2;
            a--;
            if(jt && (a % 2) == 0)
                cout << "Ashish" << endl;
            else if(jt && (a % 2) != 0)
                cout << "Ayush" << endl;
            if(!jt && (a % 2) == 0)
                cout << "Ayush" << endl;
            else if(!jt && (a % 2) != 0)
                cout << "Ashish" << endl;
        } 

    }


    return 0;
}