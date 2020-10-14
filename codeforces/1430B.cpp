#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N, K;
lli a[200000];


int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> N >> K;
        for(int i = 0; i < N; i++) cin >> a[i];
        sort(a, a + N);
        int it = N - 2;
        for(int i = 0; i < K && it >= 0; i++){
            a[N - 1] += a[it];
            it--;
        }
        cout << a[N - 1] << endl;
    }
    return 0;
}