#include <bits/stdc++.h>
using namespace std;
 
typedef long long int lli;
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
 
/**
 * 
 * MO's Algorithm.
 * 
 * Answer queries over a segment [l, r] of the array. For example frequency of the most repeated element in the segment [l, r]
 * Requires: add(int i), del(int i), get_ans()
 * 
 * */
 
const int MAXM = 200005; // Maximun number of queries.
const int MAXN = 30005; // Maximun number of elements in the array.
 
int N; // Array size
int M; // Number of queries
int BLOCK_SIZE; // sqrt(N) Bucket size
int l, r;
 
struct Query{
    int l, r, idx;
};
 
Query queries[MAXM];
int ans[MAXM];
 
lli a[MAXN];
 
// required por coordinates compression
pair<lli, int> b[MAXN]; // ordered sequence of a
int id[MAXN]; // id to map each element of a
 

bool cmp(Query &a, Query &b){
    if(a.l / BLOCK_SIZE  == b.l / BLOCK_SIZE) return a.r > b.r;
    else return a.l / BLOCK_SIZE < b.l / BLOCK_SIZE;
}

int freq[MAXN], res;

void add(int i){
    if(!freq[id[i]]) res++; 
    freq[id[i]]++;
}
 
void del(int i){
    freq[id[i]]--;
    if(!freq[id[i]]) res--; 
}
 
int get_ans(){
    return res;
}
 
void mos(){
    BLOCK_SIZE = sqrt(N);
    // Coordinates compression for mapping elements in a[]
    for(int i = 0; i < N; i++)
        b[i] = {a[i], i};
    sort(b, b + N);
    int cid = 0;
    for(int i = 0; i < N; i++){
        if(i != 0 && b[i - 1].first != b[i].first) cid++;
        id[b[i].second] = cid;
    }
    // End of coordinates compression 
    sort(queries, queries + M, cmp);
    l = 0;
    r = -1;
    for(int i = 0; i < M; i++){
        while(r < queries[i].r) add(++r);
        while(l > queries[i].l) add(--l);
        while(r > queries[i].r) del(r--);
        while(l < queries[i].l) del(l++);
        ans[queries[i].idx] = get_ans();
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    cin >> M;
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