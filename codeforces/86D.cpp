#include <bits/stdc++.h>
using namespace std;
 
typedef long long int lli;
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

const int MAXM = 200005, MAXN = 200005;
 
int N, M, BLOCK_SIZE, l, r;
 
struct Query{
    int l, r, idx;
};
 
Query queries[MAXM];
lli ans[MAXM], a[MAXN], f[1000001], res;
  
bool cmp(Query &a, Query &b){
    if(a.l / BLOCK_SIZE  == b.l / BLOCK_SIZE) return a.r > b.r;
    else return a.l / BLOCK_SIZE < b.l / BLOCK_SIZE;
}
 
void add(int i){
    res -= f[a[i]] * f[a[i]] * a[i];
    f[a[i]]++;
    res += f[a[i]] * f[a[i]] * a[i];
}
 
void del(int i){
    res -= f[a[i]] * f[a[i]] * a[i];
    f[a[i]]--;
    res += f[a[i]] * f[a[i]] * a[i];
}
 

void mos(){
    BLOCK_SIZE = sqrt(N);
    sort(queries, queries + M, cmp);
    l = 0;
    r = -1;
    for(int i = 0; i < M; i++){
        while(r < queries[i].r) add(++r);
        while(l > queries[i].l) add(--l);
        while(r > queries[i].r) del(r--);
        while(l < queries[i].l) del(l++);
        ans[queries[i].idx] = res;
    }
}

int main(){
    io_boost;
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++){
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; 
        queries[i].r--;
        queries[i].idx = i;
    }
    mos();
    for(int i = 0; i < M; i++) cout << ans[i] << endl;
    return 0;
}