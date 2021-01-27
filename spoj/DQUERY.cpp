#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 3e4, MAXQ = 2e5, MAXA = 1e6 + 5;

struct Query{
    int l, r, idx;
};

Query q[MAXQ];
int a[MAXN], ans[MAXQ], pos[MAXA], N, Q;

struct FenwickTree{
    vector<lli> bit;
    int N;
    FenwickTree(int n){
        N = n;
        bit.assign(N, 0);
    }

    lli sum(int r){
        lli ret = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    lli sum(int l, int r){
        return sum(r) - sum(l - 1);
    }

    void add(lli val, int i){
        for(; i < N; i = i | (i + 1))
            bit[i] += val;
    }
};

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
        q[i].l--;
        q[i].r--;
    }
    sort(q, q + Q, [](auto &q1, auto &q2){ return q1.r < q2.r;});
    FenwickTree tree(N);
    memset(pos, -1, sizeof(pos));
    int j = 0;
    for(int i = 0; i < N; i++){
        if(pos[a[i]] != -1) tree.add(-1, pos[a[i]]);
        pos[a[i]] = i;
        tree.add(1, i);
        while(j < Q && q[j].r == i){
            if(q[j].l == 0) ans[q[j].idx] = tree.sum(i); 
            else ans[q[j].idx] = tree.sum(i) - tree.sum(q[j].l - 1);
            j++;
        }
    }
    for(int i = 0; i < Q; i++) cout << ans[i] << endl;
    return 0;
}