/**
 * 
 * MO's Algorithm.
 * 
 * Answer queries over a segment [l, r] of the array. For example frequency of the most repeated element in the segment [l, r]
 * Requires: add(int i), del(int i), get_ans()
 * 
 * Time Complexity N * N / BLOCK_SIZE + BLOCK_SIZE * M  
 * 
 * */
 
const int MAXM = 500005; // Maximun number of queries.
const int MAXN = 500005; // Maximun number of elements in the array.
 
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
 
void add(int i){

}
 
void del(int i){

}
 
int get_ans(){
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

 