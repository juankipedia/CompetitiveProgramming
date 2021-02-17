/**
 * SPARSE TABLE:
 * 
 * Sparse Table is a data structure, that allows answering range queries. It can answer most range queries in O(logn),
 * but its true power is answering range minimum queries (or equivalent range maximum queries). For those queries it 
 * can compute the answer in O(1) time. The only drawback of this data structure is, that it can only be used on immutable 
 * arrays. This means, that the array cannot be changed between two queries. If any element in the array changes, the 
 * complete data structure has to be recomputed.
 *  
 **/

// MAXN: maximum amount of elements in a[], LOG2N = log2(MAXN)
const int MAXN = 100000, LOG2N = 17;

// lg2[i]: log2(1), st[][]: sparse table, a[]: array of elements
int lg2[MAXN + 1], st[MAXN][LOG2N + 1], a[MAXN], N;

void build(std::function<int(int, int)> f){
    // Delete this if the query does not need it
    lg2[1] = 0;
    for(int i = 2; i <= N; i++) lg2[i] = lg2[i / 2] + 1;
    
    for(int i = 0; i < N; i++) st[i][0] = a[i];
    // st[i][j] is the answer for the range [i, i + 2^j - 1]
    for(int j = 1; j <= LOG2N; j++)
        for(int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

// Find minimum in [L, R]

int minimum(int L, int R){
    int lg = lg2[R - L + 1];
    return min(st[L][lg], st[R - (1 << lg) + 1][lg]);
}

// Find sum of elements in [L, R]
int sum(int L, int R){
    int ans = 0;
    for(int i = LOG2N; i >= 0; i--){
        if(R - L + 1 >= (1 << i)){
            ans += st[L][i];
            L += (1 << i);
        }
    }
    return ans;
}