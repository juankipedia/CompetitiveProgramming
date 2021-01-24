#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, M;
const int MAXN = 1e5 + 5;

lli a[MAXN];

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
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    lli bi;
    for(int i = 0; i < N; i++){
        cin >> bi; 
        a[i] -= bi;
        a[i] = a[i] * a[i];
    }
    FenwickTree FT(a, N);
    cin >> M;
    for(int i = 0, l, r; i < M; i++){
        cin >> l >> r;
        l--; r--;
        cout << std::fixed << std::setprecision(9) << sqrt(FT.sum(l, r)) << endl;
    }
    return 0;
}