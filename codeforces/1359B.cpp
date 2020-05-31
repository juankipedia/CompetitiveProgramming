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

int t, n, m, x, y;
string ma[100];
ulli c;
int main() {
    cin >> t;
    while(t--){
        cin >> n >> m >> x >> y;
        for(int i = 0; i < n; i ++)
            cin >> ma[i];
        c  = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(ma[i][j] == '.'){
                    if(j + 1 != m && ma[i][j + 1] == '.'){
                        if(y < 2 * x){
                            ma[i][j + 1] = ma[i][j] = '*';
                            c += y;
                        }
                        else{
                            ma[i][j + 1] = ma[i][j] = '*';
                            c += 2 * x;
                        }
                    }
                    else{
                        ma[i][j] = '*';
                        c += x;
                    }
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}