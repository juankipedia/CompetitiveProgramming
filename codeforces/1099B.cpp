#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> v_i;
typedef vector<long long int> v_lli;
typedef vector<unsigned int> v_ui;
typedef vector<unsigned long long int> v_ulli;
typedef set<int> s_i;
typedef set<long long int> s_lli;
typedef set<unsigned int> s_ui;
typedef set<unsigned long long int> s_ulli;
typedef unordered_set<int> u_s_i;
typedef unordered_set<long long int> u_s_lli;
typedef unordered_set<unsigned int> u_s_ui;
typedef unordered_set<unsigned long long int> u_s_ulli;

int main() {
    ui n;
    cin >> n;
   
    if(n == 1)
        cout << 2 << endl;
    else if(n == 2)
        cout << 3 << endl;
    else{
        ui r = sqrt(n);
        if(r * r == n)
            cout << r * 2 << endl;
        else{
            ui j = 0;
            for (ui i = r * r; i < n; i += r)
                j++;
            cout << r * 2 + j << endl;
        }
    }
    return 0;
}