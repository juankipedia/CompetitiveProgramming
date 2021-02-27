#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N;

int main(){
    cin >> N;
    lli A, P, X;
    lli mini = numeric_limits<lli>::max();
    for(int i = 0; i < N; i++){
        cin >> A >> P >> X;
        if(A < X) mini = min(P, mini);
    }
    if(mini == numeric_limits<lli>::max()) cout << -1 << endl;
    else cout << mini << endl;
    return 0;
}