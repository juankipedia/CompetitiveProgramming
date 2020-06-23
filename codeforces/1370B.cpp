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

int t, n, a[2000];

int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> e, o;
        for(int i = 0; i < (2 * n); i++){
            cin >> a[i];
            if(a[i] % 2) o.push_back(i + 1);
            else e.push_back(i + 1);
        }

        int ne = e.size(), no = o.size();
        if(ne % 2 == 0){
            if(ne > 0) ne = ne - 2;
            else no = no - 2;
        }
        else{
            ne = ne - 1;
            no = no - 1;
        }

        if(ne != 0)
            for(int i = 0, j = ne - 1; i < ne / 2; i++, j--) 
                cout << e[i] << " " << e[j] << endl;
            if(no != 0)
            for(int i = 0, j = no - 1; i < no / 2; i++, j--) 
                cout << o[i] << " " << o[j] << endl;

    }
    return 0;
}