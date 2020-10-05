#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


void solve() {
    int n;
    cin >> n;
 
    map<lli, int> cnt;
    lli c = 0, now = 0;
 
    cnt[0]++;
    while(n--) {
        lli v;
        cin >> v;
 
        now += v;
        if(cnt[now]){
            c++;
            cnt.clear();
            cnt[0]++;
            now = v;
        }
        cnt[now]++;
    }
 
    cout << c << endl;
    
}
 
int main() {
    io_boost;
    solve();
    
    return 0;
}