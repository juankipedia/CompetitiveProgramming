# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int t;
lli P;
set<int> divisors(int n){
    set<int> d;
    for(int i = 1; i * i <= n; i++)
        if(n % i == 0)
            if(n / i == i) d.insert(i);
            else d.insert(i), d.insert(n / i);
    return d;
}

int main(){
    cin >> t;
    while(t--){
        cin >> P;
        cout << 2 << " " << P - 1 << endl;
    }
    return 0;
}

