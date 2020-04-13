#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;

int t, n, ai;
size_t maxi;


int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        map<size_t, size_t> a;
        for(int i = 0; i < n; i++){
            cin >> ai;
            if(a.find(ai) == a.end()) a[ai] = 1;
            else a[ai]++;
        }
        maxi = 0;
        for(const auto &e: a)
            maxi = max(e.second, maxi);
        if(maxi == 0 && a.size() > 1) cout << 1 << endl;
        else if(a.size() > maxi) cout << maxi << endl;
        else cout << min(maxi - 1, a.size()) << endl;
    }
    
    return 0;
}