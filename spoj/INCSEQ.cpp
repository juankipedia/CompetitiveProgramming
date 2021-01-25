#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const int MOD = 5e6, MAXN = 1e4 + 5;
int N, K, a[MAXN], b[MAXN];
 
struct FenwickTree{
    vector<int> bit;
    int N;
    FenwickTree(int n){
        N = n;
        bit.assign(N, 0);
    }
 
    int sum(int r){
        int ret = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1)
            ret = (ret + bit[r] % MOD) % MOD;
        return ret;
    }
    
    void add(lli val, int i){
        for(; i < N; i = i | (i + 1))
            bit[i] = (bit[i] + val) % MOD;
    }
};
 
int main(){
    io_boost;
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> a[i], b[i] = 1;
    int ans = 0;
    for(int i = 1; i <= K; i++){
        FenwickTree tree(100001);
        for(int j = 0; j < N; j++){
            tree.add(b[j], a[j]);
            b[j] = tree.sum(a[j] - 1);
        }
        if(i == K){
            ans = tree.sum(100001);
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}  