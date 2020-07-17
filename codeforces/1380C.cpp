#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, mt[100000], m[100000], ti;
lli x, a[100000];

int f(int i){
    if(i == n) return 0;
    if(i > n) return -1;
    if(mt[i] == ti) return m[i];
    mt[i] = ti;
    int next = ((x + a[i] - 1) / a[i]) - 1, ans;
    ans  = max(1 + f(i + next + 1), f(i + 1));
    m[i] = ans;
    return ans;
}

int main(){
    io_boost;
    cin >> t;
    for(ti = 1; ti <= t; ti ++){
        cin >> n >> x;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        cout << f(0) << endl;
    }
    
    return 0;
}