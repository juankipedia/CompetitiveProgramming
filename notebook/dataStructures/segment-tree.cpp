#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

/**
 *
 * SEGMENT TREE.
 * segment tree for the sum with no lazy propagation.
 * O(log(N)) per query.
 * 
 * */

const int MAXN = 100000;
int N;
lli a[MAXN], st[3 * MAXN];

# define R 2 * si + 2
# define L 2 * si + 1
# define M l + (r - l) / 2

lli build(int l, int r, int si){
    if(l == r) return st[si] = a[l];
    int mid = M;
    return st[si] = build(l, mid, L) + build(mid + 1, r, R); 
}

lli get_sum(int l, int r, int si, int ql, int qr){
    if(ql <= l && r <= qr) return st[si];
    if(l > qr || r < ql) return 0;
    int mid = M;
    return get_sum(l, mid, L, ql, qr) + get_sum(mid + 1, r, R, ql, qr);   
}

lli update(int l, int r, int si, int i, lli val){
    if(l == r) return a[i] = st[si] = val;
    int mid = M;
    if(i <= mid) return st[si] = update(l, mid, L, i, val) + st[R];
    else return st[si] = st[L] + update(mid + 1, r, R, i, val);
}