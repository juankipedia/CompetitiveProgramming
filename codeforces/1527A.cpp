# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int p = log2(n);
        cout << ((1 << p) - 1) << endl;;
    }
    return 0;
}