#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli mod = 1000000007;

string n;
lli N, T[100005], ST[100005];


int main(){
    cin >> n;
    N = n.size();
    T[0] = 1;
    for(int i = 1; i < N; i++) T[i] = (T[i - 1] * 10) % mod;
    ST[N] = 0;
    for(int i = N - 1; i >= 0; i--) ST[i] = (ST[i + 1] + T[N - 1 - i]) % mod;

    lli pre = 0, sum = 0;

    for(int i = 0; i < N - 1; i++){
        pre = ((pre * 10) % mod + (n[i] - '0')) % mod;
        sum = (sum + (pre * ST[i + 1]) % mod) % mod;         
    }

    pre = 0;

    for(int i = N - 1; i > 0; i--){
        pre = (pre + ((n[i] - '0') * T[N - 1 - i]) % mod) % mod;
        sum = (sum + (pre * i) % mod) % mod;
    }

    cout << sum << endl;
    return 0;
}