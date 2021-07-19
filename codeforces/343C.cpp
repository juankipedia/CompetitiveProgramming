#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, m;
string s;
vector<lli> p, a;
 
bool go(lli peckman, lli l, lli r, lli t){
    if(r < peckman) return (peckman - l) <= t;
    if(peckman < l) return (r - peckman) <= t;
    return (min(r - peckman, peckman - l) + r - l) <= t;
}
 
bool check(lli t){
    lli r = 0;
    for(lli peckman: p){
        if(r == a.size()) return true;
        lli l = r;
        while(r < a.size() && go(peckman, a[l], a[r], t)) r++;
    }
    return r == a.size();
}
 
 
int main(){
    io_boost;
    cin >> n >> m;
    p.resize(n); a.resize(m);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < m; i++) cin >> a[i];
    lli lo = 0, hi = 4 * 1e10 + 5;
    while(lo < hi){
        lli mid = lo + (hi - lo) / 2;
        if(check(mid)) hi = mid;
        else lo = mid + 1;   
    }
    cout << lo << endl;
    return 0;
}