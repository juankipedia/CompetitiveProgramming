# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

typedef long double ld; 
const int MAXN = 100005;
int d, n, m[MAXN];
ld a[MAXN], s[MAXN];

pair<int, int> possible(ld x){
    s[0] = a[0] - x;
    m[0] = 0;

    for(int i = 1; i < n; i++) s[i] = s[i - 1] + (a[i] - x);
    for(int i = 1; i < n; i++)
        if(s[i] < s[m[i - 1]]) m[i] = i;
        else m[i] = m[i - 1];
 
    if(s[d - 1] >= 0) return make_pair(0, d - 1);

    for(int i = d; i < n; i++){
        if(s[i] >= 0) return make_pair(0, i);
        if(s[i] >= s[m[i - d]]) return make_pair(m[i - d] + 1, i);
    }
 
    return make_pair(-1, -1);
}
 
int main(){
    io_boost;
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> a[i];
    ld lo = 0, hi = 100;
    for(int l = 0; l < 1000; l++){
        ld x = (lo + hi) / 2;
        if(possible(x) != make_pair(-1, -1)) lo = x;
        else hi = x;
    }
    auto [l, r] = possible(lo);
    cout << l + 1 << " " << r + 1 << endl;
    return 0;
}