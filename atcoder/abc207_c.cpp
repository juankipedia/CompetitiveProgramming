# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

struct interval{
    int t, l, r;
};

bool intersect(interval &a, interval &b){
    int l = max(a.l, b.l), r = min(a.r, b.r), t = 0;
    if(l > r) return false;
    bool lo = false, ro = false;
    if(l == a.l && a.t > 2) lo = true;
    if(l == b.l && b.t > 2) lo = true;
    if(r == a.r && a.t % 2 == 0) ro = true;
    if(r == b.r && b.t % 2 == 0) ro = true;
    if(lo && ro) t = 4;
    if(lo && !ro) t = 3;
    if(!lo && ro) t = 2;
    if(!lo && !ro) t = 1;
    if(l == r && t != 1) return false;
    return true;
}

interval a[2005];
int N;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i].t >> a[i].l >> a[i].r;
    int ans = 0;
    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++)
            if(intersect(a[i], a[j])) ans++;
    cout << ans << endl;
    return 0;
}