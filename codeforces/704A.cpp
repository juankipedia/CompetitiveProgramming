#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

struct Query{
    int type, x, t;
};

const int MAXN = 300005;
int n, q;
Query queries[MAXN];
int fq[MAXN];
lli A[MAXN];


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

int main(){
    cin >> n >> q;
    int nfq = 0;
    for(int i = 0; i < q; i++){
        cin >> queries[i].type;
        if(queries[i].type == 1){
            cin >> queries[i].x;
            queries[i].x--;
            fq[nfq++] = queries[i].x;
        }
        else if(queries[i].type == 2) cin >> queries[i].x, queries[i].x--;
        else cin >> queries[i].t;
    }#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
struct Query{
    int type, x, t;
};
 
const int MAXN = 300005;
int n, q;
Query queries[MAXN];
int fq[MAXN];
lli A[MAXN];
 
 
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
 
int main(){
    cin >> n >> q;
    memset(fq, -1, sizeof(fq));
    for(int i = 0; i < q; i++){
        cin >> queries[i].type;
        if(queries[i].type == 1){
            cin >> queries[i].x;
            queries[i].x--;
            fq[i] = queries[i].x;
        }
        else if(queries[i].type == 2) cin >> queries[i].x, queries[i].x--;
        else cin >> queries[i].t;
    }
    FenwickTree tree(A, n);
    int last[n];
    memset(last, -1, sizeof(last));
    for(int i = 0, j = 0, k = 0; i < q; i++){
        if(queries[i].type == 1){
            tree.add(1, queries[i].x);
            A[queries[i].x]++;
        }
        else if(queries[i].type == 2){
            tree.add(-A[queries[i].x], queries[i].x);
            A[queries[i].x] = 0;
            last[queries[i].x] = i; 
        }
        else{
            while(k < queries[i].t){
                if(fq[j] != -1 && j > last[fq[j]] && A[fq[j]]){
                    A[fq[j]]--;
                    tree.add(-1, fq[j]);
                }
                if(fq[j] != -1) k++;
                j++;
            }
        }
        cout << tree.sum(0, n - 1) << endl;
    }
    return 0;
}
    FenwickTree tree(A, n);
    bool sq[n] = {false};
    for(int i = 0, j = 0; i < q; i++){
        if(queries[i].type == 1){
            tree.add(1, queries[i].x);
            A[queries[i].x]++;
            sq[queries[i].x] = false;
        }
        else if(queries[i].type == 2){
            tree.add(-A[queries[i].x], queries[i].x);
            A[queries[i].x] = 0;
            sq[queries[i].x] = true;
        }
        else{
            while(j < queries[i].t){
                if(!sq[fq[j]] && A[fq[j]]){
                    A[fq[j]]--;
                    tree.add(-1, fq[j]);
                }
                j++;
            }
        }
        cout << tree.sum(0, n - 1) << endl;
    }
    return 0;
}