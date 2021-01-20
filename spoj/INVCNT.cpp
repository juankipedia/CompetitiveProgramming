#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 200000 + 5;
int t, n, a[MAXN];
lli A[10000005];

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
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        int maxi = 0;
        for(int i = 0; i < n; i++) cin >> a[i], maxi = max(maxi, a[i]);
        memset(A, 0, sizeof(A));
        FenwickTree tree(A, maxi + 1);
        lli ans = 0;
        for(int i = 0; i < n; i++){
            ans += tree.sum(a[i], maxi);
            tree.add(1, a[i]);
        }
        cout << ans << endl;
    }
    
    return 0;
}