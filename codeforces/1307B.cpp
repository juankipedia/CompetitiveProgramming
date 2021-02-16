#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, d;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> d;
        set<int> s;
        for(int i = 0, A; i < n; i++){
            cin >> A;
            s.insert(A);
        }
        if(s.count(d)) cout << 1 << endl;
        else cout << max(2, ( d + *s.rbegin() - 1) / *s.rbegin()) << endl;
    }
    return 0;
}