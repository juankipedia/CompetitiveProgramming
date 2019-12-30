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

int t;
lli a, b, c, r, cnt, lb, ub;

int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> r;
        cnt = 0;
        lb = c - r;
        ub = c + r;
        if(a > b) swap(a, b);
        if(lb > a && lb < b)
            cnt = lb - a;
        if(ub < b && ub > a)
            cnt += b - ub; 
        if(ub <= a || lb >= b )
            cnt = b - a;
        cout << cnt << endl;
    }
    return 0;
}