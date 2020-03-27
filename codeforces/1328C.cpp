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

int t, n;
string x, a , b;

int main() {
    cin >> t;
    while(t--){
        cin >> n;
        cin >> x;
        a = b = "1";
        bool e = false;
        if(n == 1){
            cout << a << endl << b << endl;
            continue;
        }
        if(x[1] == '0'){
            a += "0"; b += "0";
            e = true;
        }
        else if(x[1] == '1'){
            a += "1"; b += "0";
        }
        else{
            a += "1"; b += "1";
            e = true;
        }

        for(int i = 2; i < n; i++){
            if(e && x[i] == '2'){
                a += "1"; b += "1";
                continue;
            }
            else if(e && x[i] == '0'){
                a += "0"; b += "0";
                continue;
            }
            else if(e && x[i] == '1'){
                b += "0"; a += "1"; e = false;
                continue;
            }

            if(x[i] == '0'){
                b += "0"; a += "0"; e = false;
            }
            else if(x[i] == '1'){
                b += "1"; a += "0"; e = false;
            }
            else{
                a += "0"; b += "2"; e = false;
            }
        }
        cout << a << endl << b << endl;

    }
    return 0;
}