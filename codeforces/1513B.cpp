# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef pair<int, int> pii;

lli f(lli n){
    if(n >= lli(1e9 + 7)){
        return 0;
    }
    lli ans = 1;
    for(lli i = 1; i <= n; i++){
        ans = (ans * i) % lli(1e9 + 7);
    }
    return ans;
}

int main(){
    io_boost;
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        map<lli, lli> m, fact_map;
        lli first;
        cin >> first;
        m[first]++;
        for(int i = 1, ai; i < n; i++){
            cin >> ai;
            m[ai]++;
            first = first & ai;
        }
        if(!m.count(first)){
            cout << 0 << endl;
            continue;
        }
        if(m[first] < 2){
            cout << 0 << endl;
            continue;
        }
        lli ans = (m[first] * (m[first] - 1)) % lli(1e9 + 7);
        ans *= f(n - 2) % lli(1e9 + 7);
        cout <<  ans % lli(1e9 + 7) << endl;
    }
    return 0;
}