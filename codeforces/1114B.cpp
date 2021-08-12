# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

const int MAXN = 200005;
int n, m, k, a[MAXN], b[MAXN];


int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
    sort(b, b + n, greater<int>());
    multiset<int> s;
    for(int i = 0; i < m * k; i++) s.insert(b[i]);
    lli sum = 0;
    for(int i = 0; i < m * k; i++) sum += b[i];
    cout << sum << endl;
    for(int i = 0, mi = 0; i < n; i++){
        if(s.count(a[i])){
            s.erase(s.lower_bound(a[i]));
            mi++;
            if(s.empty()) break;
        }
        if(mi == m) cout << i + 1 << " ", mi = 0;
    }
    cout << endl;
    return 0;
}