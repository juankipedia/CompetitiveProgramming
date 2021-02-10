#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const lli MAXM = 100005; // Maximun number of queries.
const lli MAXN = 100005; // Maximun number of elements in the array.
 
lli N; // Array size
lli M; // Number of queries
lli BLOCK_SIZE; // sqrt(N) Bucket size
lli l, r;
 
struct Query{
    lli l, r, idx;
};
 
Query queries[MAXM];
lli ans[MAXM];
 
lli a[MAXN];
 
bool cmp(Query &a, Query &b){
    if(a.l / BLOCK_SIZE  == b.l / BLOCK_SIZE) return a.r > b.r;
    else return a.l / BLOCK_SIZE < b.l / BLOCK_SIZE;
}
 
lli cnt[1 << 20];
lli res = 0;
lli k; 
 
void add(lli i){
    res += cnt[a[i] ^ k];
    cnt[a[i]]++;
}
 
void del(lli i){
    cnt[a[i]]--;
    res -= cnt[a[i] ^ k];
}
 
lli get_ans(){
    return res;
}
 
void mos(){
    BLOCK_SIZE = sqrt(N);
    sort(queries, queries + M, cmp);
    l = 0;
    r = -1;
    for(lli i = 0; i < M; i++){
        while(r < queries[i].r) add(++r);
        while(l > queries[i].l) add(--l);
        while(r > queries[i].r) del(r--);
        while(l < queries[i].l) del(l++);
        ans[queries[i].idx] = get_ans();
    }
}
 
int main(){
    cin >> N >> M >> k;
    a[0] = 0;
    N++;
    for(lli i = 1; i < N; i++) cin >> a[i], a[i] ^= a[i - 1];
    for(lli i = 0, l, r; i < M; i++){
        cin >> l >> r;
        l--; r;
        queries[i].l  = l;
        queries[i].r = r;
        queries[i].idx = i;
    }
    mos();
    for(lli i = 0; i < M; i++) cout << ans[i] << endl;
 
    return 0;
}