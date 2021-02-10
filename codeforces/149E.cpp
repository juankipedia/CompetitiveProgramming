#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int m, ans;
string txt, p, rtxt, rp;
 
vector<int> z_function(const string &s){
    int n = s.length();
    vector<int> z(n, 0);
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r) z[i] = min (r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
 
 
 
const int MAXN = 1005, LOG2N = 10;
int lg2[MAXN + 1];
void build(int st[][LOG2N + 1], vector<int> &a){
    int N = a.size();
    lg2[1] = 0;
    for(int i = 2; i <= N; i++) lg2[i] = lg2[i / 2] + 1;
    for(int i = 0; i < N; i++) st[i][0] = a[i];
    for(int j = 1; j <= LOG2N; j++)
        for(int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
 
int maximum(int L, int R, int st[][LOG2N + 1]){
    int lg = lg2[R - L + 1];
    return max(st[L][lg], st[R - (1 << lg) + 1][lg]);
}
 
 
 
 
int main(){
    io_boost;
    cin >> txt;
    cin >> m;
    rtxt = "";
    for(int j = txt.size() - 1; j >= 0; j--) rtxt += txt[j];
    for(int i = 0; i < m; i++){
        cin >> p;
        if(p.size() == 1) continue;
        rp = "";
        for(int j = p.size() - 1; j >= 0; j--) rp += p[j];
        auto prefixes = z_function(p + "#" + txt);
        auto sufixes = z_function(rp + "#" + rtxt);
        vector<int> sm(p.size() + 1, -1);
        int l = rp.size() + 1, r = rp.size() + rtxt.size() + 1;
        
        for(int j = l; j < r; j++){
            if(sm[sufixes[j]] == -1)
                sm[sufixes[j]] = txt.size() - (j - l) - sufixes[j];
        }
        int st[MAXN][LOG2N + 1];
        build(st, sm);
        for(int j = l; j < r; j++){
            int pos = j - l, sz = p.size() - prefixes[j];
            int maxpos = maximum(sz, p.size(), st);
            if(prefixes[j] == p.size() || (maxpos >= (pos + prefixes[j]))){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}