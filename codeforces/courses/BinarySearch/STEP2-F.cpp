# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m, a[200005];
string t, p;

bool check(int c){
    bool d[n] = {false};
    for(int i = 0; i < c; i++) d[a[i]] = true;
    int j = 0;
    for(int i = 0; i < n && j < m; i++){
        if(d[i]) continue;
        if(t[i] == p[j]) j++;
    }
    return j == m;
}

int main(){
    cin >> t >> p;
    n = t.size();
    m = p.size();
    for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
    int lo = -1, hi = n;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
    return 0;
}