#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli x;
vector<lli> a, m;

int main(){
    io_boost;
    cin >> t;
    while (t--){
        cin >> n >> x;
        lli sum = 0;
        lli ai;
        a.clear(); m.clear();
        for(int i = 0; i < n; i++){
            cin >> ai;
            a.push_back(ai);
            m.push_back(1);
            sum += a[i];
        }
        for(int i = 0; i < a.size(); i++){
            if(a[i] % x) break;
            sum += a[i] * m[i];
            a.push_back(a[i] / x);
            m.push_back(x * m[i]);
        }
        cout << sum << endl;
    }

    return 0;
}