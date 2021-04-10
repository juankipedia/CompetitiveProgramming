# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, m;
map<int, int> S2;
lli ans, sum;
map<int, int>::iterator nd;

bool prime_factors(int n){
    int sum = n;
    map<int, int> S;
    while(n % 2 == 0) S[2]++, n = n/2;
    for(int i = 3; i * i <= n; i = i + 2)  
        while(n % i == 0) S[i]++, n = n/i;
    if(n > 2) S[n]++;
    if(S.size() != S2.size()) return false;
    for(auto e: S){
        if(!S2.count(e.first) || S2[e.first] != e.second) return false;
    }
    return true;
}

void solve(map<int, int>::iterator &it){
    if(it == nd){
        if(!sum || !S2.size()) return;
        if(prime_factors(sum)) ans = max(ans, sum);
        return;
    }
    for(int i = 0; i <= it->second; i++){
        if(i != 0) sum += it->first * i;
        if(it->second - i != 0) S2[it->first] = it->second - i;
        it++;
        solve(it);
        it--;
        sum -= it->first * i;
        S2.erase(it->first);
    }
}


int main(){
    io_boost;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> m;
        ans = sum = 0;
        map<int, int> N;
        for(int i = 0, pi, ni; i < m; i++){
            cin >> pi >> ni; 
            N[pi] = ni;
        }
        auto it = N.begin();
        nd = N.end();
        solve(it);
        cout << "Case #" << ti << ": " <<  ans << endl;
    }
    return 0;
}