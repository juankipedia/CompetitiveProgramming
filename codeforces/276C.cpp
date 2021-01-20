#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 2e5 + 5;
int N, q, in[MAXN], de[MAXN];
lli a[MAXN], A[MAXN];
pair<int, int> m[MAXN];

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
    cin >> N >> q;
    for(int i = 0; i < N; i++) cin >> a[i];
    int qs[q], qe[q];
    for(int i = 0; i < q; i++){
        cin >> qs[i] >> qe[i];
        qs[i]--; qe[i]--;
        in[qs[i]]++;
        de[qe[i]]++;
    }
    int cur = 0;
    for(int i = 0; i < N; i++){
        cur += in[i];
        m[i] = {cur, i};
        cur -= de[i];
    }
    sort(m, m + N);
    sort(a, a + N);
    for(int i = 0; i < N; i++) A[m[i].second] = a[i];
    FenwickTree t(A, N);
    lli ans = 0;
    for(int i = 0; i < q; i++)
        ans += t.sum(qs[i], qe[i]);
    cout << ans << endl;
    return 0;
}