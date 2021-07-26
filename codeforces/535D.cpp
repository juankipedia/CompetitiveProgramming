# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

const lli MOD = 1000000007;
const int MAXN = 1e6 + 5;
int n, m;
string p;
lli h[MAXN], b[MAXN];

void rolling_hash(string &s, lli B = 31, lli p = MOD){
    h[0] = 0;
    h[1] = (s[0] - 'a' + 1);
    b[0] = 1;
    for(int i = 1; i < s.size(); i++){
        h[i + 1] = ((h[i] * B) % p + (s[i] - 'a' + 1LL)) % p;
        b[i] = (B * b[i - 1]) % p;   
    }
}


lli get_hash(int l, int r, lli p = MOD){
    return (h[r + 1] - ((h[l] * b[r - l + 1]) % p) + p) % p;
}

int o[MAXN], c[MAXN], y[MAXN];

int main(){
    io_boost;
    cin >> n >> m;
    cin >> p;
    rolling_hash(p);
    bool ok = true;
    for(int i = 0; i < m; i++) cin >> y[i], y[i]--;
    int l = -1, r = -1;
    for(int i = 0, j; i < m; i++){
        j = y[i];
        if(j <= r){
            if(get_hash(j - l, p.size() - 1) != get_hash(0, p.size() - (j - l) - 1)){
                ok = false;
                break;
            }
        }
        l = j, r = j + p.size() - 1;
        o[l]++;
        c[r]++;
    }
    if(!ok){
        cout << 0 << endl;
        return 0;
    }
    lli ans = 1;
    int in = 0;
   
    for(int i = 0; i < n; i++){
        if(o[i] && !c[i]) in++;
        if(!in && !o[i] && !c[i]) ans = (ans * 26) % MOD;
        if(c[i] && !o[i]) in--;
    }
    cout << ans << endl;
    return 0;
}