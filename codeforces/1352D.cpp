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

int n, t, a[1000], l, r, at, bt, as, bs, c;
bool tb;
int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        c = at = bt = l = 0; r = n - 1;
        tb = true; 
        as = bs = 0;
        while(l <= r){
            c++;
            if(tb){
                as = 0;
                while( l <= r && !(as > bs)){
                    as += a[l];
                    l ++; 
                }
                at += as;
                tb = !tb;
            }
            else{
                bs = 0;
                while( l <= r && !(bs > as)){
                    bs += a[r];
                    r--; 
                }
                bt += bs;
                tb = !tb;
            }
        }
        cout << c << " " << at << " " << bt << endl;
    }
    return 0;
}