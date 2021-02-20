#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string N;
int K;

int main(){
    io_boost;
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        sort(N.begin(), N.end(), greater<char>());
        string g1 = N;
        sort(N.begin(), N.end());
        N = to_string(stoll(g1) - stoll(N));
    }
    cout << N << endl;
    return 0;
}