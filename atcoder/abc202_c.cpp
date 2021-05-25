# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 7;
int N, A[MAXN], B[MAXN];

int main(){
    cin >> N;
    map<int, vector<int>> m;
    map<int, int> m2;
    for(int i = 0; i < N; i++) cin >> A[i], m[A[i]] = {}, m2[A[i]]++;
    for(int i = 0; i < N; i++){
        cin >> B[i];
        if(m.count(B[i])) m[B[i]].push_back(i + 1);
    }
    multiset<int> C;
    lli ans = 0;
    for(int i = 0, Ci; i < N; i++) cin >> Ci, C.insert(Ci);
    for(auto &[k, v] : m){
        for(int p: v)
            ans += m2[k] * C.count(p);
    }

    cout << ans << endl;
    
    return 0;
}