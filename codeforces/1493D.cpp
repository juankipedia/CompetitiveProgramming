# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 2e5, MOD = 1e9 + 7;
int N, Q, a[MAXN];
map<int, int> pf[MAXN];
map<int, multiset<int>> pfm;

void primeFactors(int n, int idx){
    while(n % 2 == 0) pf[idx][2]++, n = n/2;  
    for(int i = 3; i * i <= n; i = i + 2)
        while(n % i == 0) pf[idx][i]++, n = n/i;  
    if(n > 2) pf[idx][n]++;  
    for(auto &f: pf[idx]) pfm[f.first].insert(f.second);
}

ulli fpow(ulli n, ulli e){
    ulli res = 1;
    while(e > 0ULL){
      if (e & 1) res = (res * n) % MOD;
      e >>= 1;
      n = (n * n) % MOD;
    }
    return res;
}

int ans = 1;
void primeFactors2(int n, int idx){
    map<int, int> pff;
    while(n % 2 == 0) pff[2]++, n = n/2;  
    for(int i = 3; i * i <= n; i = i + 2)
        while(n % i == 0) pff[i]++, n = n/i;  
    if(n > 2) pff[n]++;  
    for(auto &f: pff){
        int freq = 0, mini = *pfm[f.first].begin();
        if(pf[idx].count(f.first)){
            freq = pf[idx][f.first];
            pf[idx][f.first] += f.second;
        }
        else pf[idx][f.first] = f.second;

        if(freq){
            pfm[f.first].erase(pfm[f.first].find(freq));
            pfm[f.first].insert(freq + f.second);
            if(pfm[f.first].size() == N){
                int nmini = *pfm[f.first].begin();
                if(nmini > mini)
                    ans = (ans * fpow(f.first, nmini - mini)) % MOD;
            }
        }
        else{
            pfm[f.first].insert(f.second);
            if(pfm[f.first].size() == N)
                ans = (ans * fpow(f.first, *pfm[f.first].begin())) % MOD;
        }
    }
}


int main(){
    io_boost;
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        primeFactors(a[i], i);
    }
    for(auto &fm : pfm) 
        if(fm.second.size() == N) 
            ans = (ans * fpow(fm.first, *fm.second.begin())) % MOD;
    int i, x;
    while(Q--){
        cin >> i >> x;
        i--;
        primeFactors2(x, i);
        cout << ans << endl;
    }
    return 0;
}