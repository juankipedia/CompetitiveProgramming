#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, m, t, k, l, r;
 
lli st[300000];
bool sta[300000];
 
int get_kth(int ss, int se, int si, int kth){
    int mid = ss + (se - ss) / 2;
    if(sta[si]){
        sta[si] = false;
        if(ss != se){
            sta[2 * si + 1] = !sta[2 * si + 1];
            sta[2 * si + 2] = !sta[2 * si + 2];
            st[2 * si + 1] = (mid - ss + 1) - st[2 * si + 1];
            st[2 * si + 2] = (se - mid) - st[2 * si + 2];
        }
    }
    if(ss == se) return ss;
    if(st[2 * si + 1] > kth){
        return get_kth(ss, mid, 2 * si + 1, kth);
    }
    else if((kth - st[2 * si + 1]) < st[2 * si + 2]){
        return get_kth(mid + 1, se, 2 * si + 2, kth - st[2 * si + 1]);
    }
    return -1;
}
 
void inverse(int ss, int se, int si, int l, int r){
    if(l <= ss && se <= r){
        sta[si] = !sta[si];
        st[si] = (se - ss + 1) - st[si];
        return;
    }
    if(se < l || ss > r) return;
    int mid = ss + (se - ss) / 2;
    if(sta[si]){
        sta[si] = false;
        sta[2 * si + 1] = !sta[2 * si + 1];
        sta[2 * si + 2] = !sta[2 * si + 2];
        st[2 * si + 1] = (mid - ss + 1) - st[2 * si + 1];
        st[2 * si + 2] = (se - mid) - st[2 * si + 2];
    }
    inverse(ss, mid, 2 * si + 1, l, r);
    inverse(mid + 1, se, 2 * si + 2, l, r);
    st[si] = st[2 * si + 1] + st[2 * si + 2];
    return;
}
 
int main(){
    cin >> n >> m;
    while (m--){
        cin >> t;
        if(t == 1){
            cin >> l >> r;
            inverse(0, n - 1, 0, l, r - 1);
        }
        else{
            cin >> k;
            cout << get_kth(0, n - 1, 0, k) << endl;
        }
    }
    
    return 0;
}