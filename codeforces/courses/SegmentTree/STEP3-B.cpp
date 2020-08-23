#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, m, q;
 
lli a[100001], st[300000], l, r, s[100000];
 
lli build(int ss, int se, int si){
    if(ss == se) return st[si] = a[ss];
    int mid = ss + (se - ss) / 2;
    return st[si] = build(ss, mid, 2 * si + 1) + build(mid + 1, se, 2 * si + 2);
}
 
lli update(int ss, int se, int si, int i, lli v){
    if(i < ss || i > se) return st[si];
    if(ss == se){
        a[i] = v;
        return st[si] = v;
    }
    int mid = ss + (se - ss) / 2;
    return st[si] = update(ss, mid, 2 * si + 1, i, v) + update(mid + 1, se, 2 * si + 2, i, v);
}

int get_index(int ss, int se, int si, lli sum){
    if(ss == se) return ss;
    int mid = ss + (se - ss) / 2;
    if(sum > st[2 * si + 2]) return get_index(ss, mid, 2 * si + 1, sum - st[2 * si + 2]);
    else return get_index(mid + 1, se, 2 * si + 2, sum);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) a[i] = 1;
    build(0, n - 1, 0); 
    int ans[n];
    for(int i = n - 1; i >= 0; i--){
        ans[i] = get_index(0, n - 1, 0, s[i] + 1);
        update(0, n - 1, 0, ans[i], 0);
    }
    for(int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
    cout << endl;    
    return 0;
}