#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

struct Operation{
    int l, r;
    lli val;
};

const int MAXN = 1e5 + 5;
int n, m, k;
lli a[MAXN];
Operation op[MAXN];


struct FenwickTree{
    vector<lli> bit;
    int N;
    FenwickTree(lli a[], int n){
        N = n;
        bit.assign(N, 0);
        for(int i = 0; i < N; i++)
            add(a[i], i);

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

int in[MAXN], de[MAXN], times[MAXN];
lli A[MAXN];

int main(){
    cin >> n >> m >> k;
    FenwickTree tree(A, n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        cin >> op[i].l >> op[i].r >> op[i].val;
        op[i].l--; op[i].r--;
    }

    for(int i = 0, l, r; i < k; i++){
        cin >> l >> r;
        l--; r--;
        in[l]++;
        de[r]++;
    }
    int cur = 0;
    for(int i = 0; i < m; i++){
        cur += in[i];
        times[i] = cur;
        cur -= de[i];
    }

    for(int i = 0; i < m; i++){
        op[i].val  *= times[i];
        tree.add(op[i].val, op[i].l);
        tree.add(-op[i].val, op[i].r + 1);
    }

    for(int i = 0; i < n; i++){
        //cout << times[i] << " ";
        cout << a[i] + tree.sum(i) << " ";
    }
    cout << endl;

    return 0;
}