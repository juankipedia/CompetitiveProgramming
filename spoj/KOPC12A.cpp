#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 10000;

int t, N;
lli H[MAXN], C[MAXN];

lli f(lli h){
    lli ans = 0;
    for(int i = 0; i < N; i++)
        ans += abs(H[i] - h) * C[i];
    return ans;
}

int main(){
    cin >> t;
    while(t--){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> H[i];
        for(int i = 0; i < N; i++) cin >> C[i];
        lli lo = 0, hi = 1e4;
        for(int i = 0; i < 100; i++){
            int m2 = hi - (hi - lo) / 3, m1 = lo + (hi - lo) / 3;
            //cout << f(m1) << " " << f(m2) << " " << m1 << " " << m2 << endl; 
            if(f(m1) > f(m2)) lo = m1;
            else hi = m2;
        }
        if(lo == hi) cout << f(lo) << endl;
        else cout << f(lo + 1) << endl;
    }
    return 0;
}