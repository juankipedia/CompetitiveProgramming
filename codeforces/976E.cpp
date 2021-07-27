# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

const int MAXN = 200005;
int n, a, b, pos[MAXN];
lli h[MAXN], d[MAXN];

bool cmp(int i, int j){
    return (h[i] - d[i]) > (h[j] - d[j]);
}

int main(){
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) cin >> h[i] >> d[i];
    b = min(b, n);
    for(int i = 0; i < n; i++) pos[i] = i; 
    sort(pos, pos + n, cmp);
    lli sum = 0;
    for(int i = 0; i < n; i++){
        if(i < b) sum += h[pos[i]] > d[pos[i]] ? h[pos[i]] : d[pos[i]];
        else sum += d[pos[i]];
    }
    if(b == 0){ cout << sum << endl; return 0; }

    lli ans = sum, power = (1LL << a);
    for(int i = 0; i < n; i++){
        int p = pos[i];
        lli sumi = sum;
        if(i < b){
            sumi -= h[p] > d[p] ? h[p] : d[p];
            sumi += power * h[p];
            ans = max(ans, sumi);
        }
        else{
            sumi -= d[p];
            sumi += power * h[p];
            sumi -= h[pos[b - 1]] > d[pos[b - 1]] ? h[pos[b - 1]] : d[pos[b - 1]];
            sumi += d[pos[b - 1]];
            ans = max(ans, sumi);
        }
    }
    cout << ans << endl;
    return 0;
}