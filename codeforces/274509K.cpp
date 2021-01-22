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

const int MAXN = 1000 + 5;
int N, M, K, t;
pair<int, int> a[MAXN * MAXN];

int main(){
    io_boost;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> N >> M >> K;
        for(int i = 0; i < K; i++){
            cin >> a[i].first >> a[i].second;
            a[i].first--;
            a[i].second--;
        }
        sort(a, a + K);
        lli A[M + 5] = {0};
        FenwickTree tree(A, M + 5);
        lli ans = 0;
        for(int i = 0; i < K; i++){
            ans += tree.sum(a[i].second + 1, M);
            tree.add(1, a[i].second);
        }
        cout << "Test case "<< ti << ": " << ans << endl;
    }
    return 0;
}