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

const int MAXN = 1e5 + 5;
int N;
lli A[MAXN][2];

int main(){
    cin >> N;
    
    FenwickTree tree1(A[0], N + 1), tree2(A[1], N + 1);
    lli ans = 0;
    for(int i = 0, ai; i < N; i++){
        cin >> ai;
        ans += tree2.sum(ai + 1, N);
        tree2.add(tree1.sum(ai + 1, N), ai);
        tree1.add(1, ai);
    }

    cout << ans << endl;
    

    return 0;
}