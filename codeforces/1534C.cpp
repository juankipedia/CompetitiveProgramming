# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


const int MAXN = 400005;
int N, parent[MAXN];

void build(){
    for(int i = 0; i < N; i++) parent[i] = i;
}

int find(int a){
    if(parent[a] != a) parent[a] = find(parent[a]);
    return parent[a];
}

void join(int a, int b){
    parent[find(a)] = find(b); 
}

int t, m[2][400005];
const int MOD = 1e9 + 7;

ulli fast_pow(ulli n, ulli e){
    ulli res = 1;
    n %= MOD;
    if(n == 0) return 0;
    while(e > 0ULL){
      if(e & 1) res = (res * n) % MOD;
      e >>= 1;
      n = (n * n) % MOD;
    }
    return res;
}

int main(){
    cin >> t;
    while(t--){
        cin >> N;
        build();
        for(int i = 0; i < N; i++) cin >> m[0][i], m[0][i]--;
        for(int i = 0; i < N; i++) cin >> m[1][i], m[1][i]--;;
        for(int i = 0; i < N; i++) join(m[0][i], m[1][i]);
        set<int> s;
        for(int i = 0; i < N; i++) s.insert(find(m[0][i]));
        cout << fast_pow(2, s.size()) << endl; 
    }

    return 0;
}