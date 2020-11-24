#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[200000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        map<int, pair<int, int>> f;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            if(f.find(a[i]) == f.end()) f[a[i]] = {i, i == 0 ? 0 : 1};
            else if(f[a[i]].first == i - 1) f[a[i]] = {i, f[a[i]].second};
            else f[a[i]] = {i, f[a[i]].second + 1};
        }
        for(auto & p: f)
            if(p.first != a[n - 1]) p.second.second++;
        int mini = 200005;
        for(auto &p: f){
            mini = min(p.second.second, mini);
        }
        cout << mini << endl;
    }
    return 0;
}