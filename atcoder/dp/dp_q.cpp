#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const int MAXN = 200000;
int N;

struct FenwickTree{
    vector<lli> bit;
    int n;
    
    FenwickTree(int N){
        n = N;
        bit.assign(n, 0);        
    }
    
    lli maximun(int r){
        lli ret = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1)
            ret  = max(ret, bit[r]);
        return ret;
    }

    void set(int i, lli value){
        for(; i < n; i = i | (i + 1))
            bit[i] = max(value, bit[i]);
    }
};

 
int h[MAXN];
lli b[MAXN];
 
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> h[i], h[i]--;
    for(int i = 0; i < N; i++) cin >> b[i];
    lli ans = 0;
    FenwickTree t(N + 5);
    for(int i = 0; i < N; i++){
        lli maxi = t.maximun(h[i]) + b[i];
        t.set(h[i], maxi);
        ans = max(maxi, ans);
    }
    cout << ans << endl;
    return 0;
}