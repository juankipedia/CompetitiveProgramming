# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

set<int> factors;
void prime_factors(int n){
    while(n % 2 == 0) factors.insert(2), n = n / 2;  
    for(int i = 3; i * i <= n; i = i + 2)  
        while(n % i == 0) factors.insert(i), n = n / i;
    if(n > 2) factors.insert(n);
}

bool check(int n){
    set<int> f;
    while(n % 2 == 0) f.insert(2), n = n / 2;  
    for(int i = 3; i * i <= n; i = i + 2)  
        while(n % i == 0) f.insert(i), n = n / i;
    if(n > 2) f.insert(n);
    for(int e : f) if(factors.count(e)) return false;
    return true;
}

int main(){
    io_boost;
    int N, M;
    cin >> N >> M;
    for(int i = 0, A; i < N; i++) cin >> A, prime_factors(A);
    vector<int> ans;
    //cout << factors.count(1) << endl;
    for(int i = 1; i <= M; i++)
        if(check(i)) ans.push_back(i);
    cout << ans.size() << endl;
    for(int e : ans) cout << e << endl;
    return 0;
}