# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli B = 31;
const lli MOD = 1e9 + 7;
 
void rolling_hash(string &s, lli h[], lli b[], lli p = MOD){
    h[0] = 0;
    h[1] = (s[0] - 'a' + 1);
    b[0] = 1;
    for(int i = 1; i < s.size(); i++){
        h[i + 1] = ((h[i] * B) % p + (s[i] - 'a' + 1LL)) % p;
        b[i] = (B * b[i - 1]) % p;   
    }
}
 
lli get_hash(int l, int r, lli h[], lli b[], lli p = MOD){
    return (h[r + 1] - ((h[l] * b[r - l + 1]) % p) + p) % p;
}
 
int n;
vector<string> m;
int x, y;
lli mh[2000][2000], mh2[2000][2000];
lli b[2000][2000], b2[2000][2000];

lli get_hash2(int l, int r, int c){
    return (mh2[r + 1][c] - ((mh2[l][c] * b2[r - l + 1][c]) % MOD) + MOD) % MOD;
}
 
bool check(int i, int j){
    int dr = 0;
    for(int r = 0; r < n; r++)
        if(get_hash2(i, i + r, j) != get_hash2(x, x + r, y)){
            dr = r;
            break;
        }
    for(int c = 0; c < n; c++)
        if(m[i + dr][j + c] < m[x + dr][y + c]) return true;
        else if(m[i + dr][j + c] > m[x + dr][y + c]) return false;
    return true;
}
 
int main(){
    io_boost
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
    string r;
    while(cin >> r) m.push_back(r), m.back() += m.back();
    n = m[0].size() / 2;
    for(int i = 0; i < n; i++) m.push_back(m[i]);
    for(int i = 0; i < m.size(); i++) rolling_hash(m[i], mh[i], b[i]);
    for(int j = 0; j < n; j++){
        mh2[0][j] = 0;
        mh2[1][j] = get_hash(j, j + n, mh[0], b[0]);
        b2[0][j] = 1;
        for(int i = 1; i < m.size(); i++){
            mh2[i + 1][j] = ((mh2[i][j] * B) % MOD + (get_hash(j, j + n, mh[i], b[i]))) % MOD;
            b2[i][j] = (B * b2[i - 1][j]) % MOD;   
        }
    }
 
    for(int di = 0; di < n; di++)
        for(int dj = 0; dj < n; dj++)
            if(check(di, dj)) x = di, y = dj;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << m[x + i][y + j];
        cout << endl;
    }
    return 0;
}