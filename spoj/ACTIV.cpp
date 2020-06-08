#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<lli, lli> p_lli;

const int MOD = 100000000;
lli A[100001];
int N;
p_lli s[100000];
string ret;

lli f(int i){
    p_lli val = {s[i].second, s[i].first};
    int pos  = upper_bound(s, s + N, val) - s;
    lli ans = 1 + A[pos] % MOD;
    return ans;
}

int main(){
    io_boost;
    while(cin >> N && N != -1){
        for(int i = 0; i < N; i++) cin >> s[i].second >> s[i].first;
        sort(s, s + N);
        A[0] = 0;
        A[1] = f(0) % MOD;
        for(int i = 1; i < N; i++)
            A[i + 1] = (A[i] % MOD + f(i) % MOD) % MOD;
        ret = to_string(A[N]);
        for(int i = 0; i < (8 - ret.size()); i++) cout << 0;
        cout << ret << endl;
    }
    return 0;
}