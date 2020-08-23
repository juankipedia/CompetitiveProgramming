#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n;
 
lli a[200001], st[600000], l, r, m[100001], A[200001], ans[100001];
 
lli build(int ss, int se, int si){
    if(ss == se) return st[si] = a[ss];
    int mid = ss + (se - ss) / 2;
    return st[si] = build(ss, mid, 2 * si + 1) + build(mid + 1, se, 2 * si + 2);
}
 
lli get_sum(int ss, int se, int si, int qs, int qe){
    if(qs <= ss && se <= qe) return st[si];
    if(qs > se || ss > qe) return 0;
    int mid = ss + (se - ss) / 2;
    return get_sum(ss, mid, 2 * si + 1, qs, qe) + get_sum(mid + 1, se, 2 * si + 2, qs, qe);
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
 
int main(){
    cin >> n;
    int n2 = (2 * n);
    for(int i = 0; i < n2; i++){
        cin >> A[i];
        A[i]--;
    }
    for(int i = 0; i < n; i++) m[i] = -1;
    for(int i = 0; i < n2; i++){
        if(m[A[i]] == -1) m[A[i]] = i;
        else{
            ans[A[i]] = get_sum(0, n2 - 1, 0, m[A[i]], i);
            update(0, n2 - 1, 0, m[A[i]], 1);
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;    
    return 0;
}