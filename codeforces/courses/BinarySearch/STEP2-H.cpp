# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

string s;
ulli n[3], p[3], f[3], r;

bool check(ulli mid){
    ulli cnt = 0;
    ulli need[] = {f[0] * mid, f[1] * mid, f[2] * mid};
    if(n[0] <= need[0]) need[0] -= n[0];
    else need[0] = 0;
    if(n[1] <= need[1]) need[1] -= n[1];
    else need[1] = 0;
    if(n[2] <= need[2]) need[2] -= n[2];
    else need[2] = 0;
    return (need[0] * p[0] + need[1] * p[1] + need[2] * p[2]) <= r;
}

int main(){
    cin >> s;
    for(char c: s) 
        if(c == 'B') f[0]++;
        else if(c == 'S') f[1]++;
        else f[2]++;
    for(int i = 0; i < 3; i++) cin >> n[i];
    for(int i = 0; i < 3; i++) cin >> p[i];
    cin >> r;
    ulli lo = 0, hi = 1e13;
    while(lo < hi){
        ulli mid = (lo + hi + 1) / 2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
    return 0;
}