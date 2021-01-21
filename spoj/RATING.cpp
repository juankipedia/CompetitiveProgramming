#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
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
 
const int MAXR = 1e5 + 5, MAXN = 3e5 + 5;
int N;
lli A[MAXR], B[MAXR];
pair<int, pair<int, int>> a[MAXN], b[MAXN];
 
int main(){
    cin >> N;
 
    for(int i = 0; i < N; i++){
        cin >> a[i].first >> a[i].second.first;
        a[i].second.second = i;
        b[i] = a[i];
        swap(b[i].first, b[i].second.first);
        A[a[i].second.first]++;
        B[b[i].second.first]++;
    }
    sort(a, a + N, greater<pair<int, pair<int, int>>>());
    sort(b, b + N, greater<pair<int, pair<int, int>>>());

    int aux[N];
    pair<int, int> prev = {a[0].first, a[0].second.first};
    FenwickTree tree(A, MAXR), treeb(B, MAXR);
    lli ans[MAXN];

    for(int i = 0; i < N; i++)
        aux[a[i].second.second] = a[i].second.second;
    ans[0] = numeric_limits<lli>::max();
    for(int i = 1; i < N; i++){
        pair<int, int> ai = {a[i].first, a[i].second.first};
        int pos = a[i].second.second, ppos = a[i - 1].second.second;
        if(ai == prev){
            aux[pos] = aux[ppos];
        }
        else prev = ai;
        ans[i] = numeric_limits<lli>::max();
    }

    for(int i = 0; i < N; i++){
        tree.add(-1, a[i].second.first);
        treeb.add(-1, b[i].second.first);
        int pos = a[i].second.second;
        if(aux[pos] != pos){
            ans[aux[pos]]--;
            continue;
        }

        ans[pos] = min(tree.sum(0, a[i].second.first), ans[pos]);
        ans[b[i].second.second] = min(treeb.sum(0, b[i].second.first), ans[b[i].second.second]);
        
    }
    for(int i = 0; i < N; i++){
        if(aux[i] != i) cout << ans[aux[i]] << endl;
        else cout << ans[i] << endl;
    
    }
    return 0;
} 