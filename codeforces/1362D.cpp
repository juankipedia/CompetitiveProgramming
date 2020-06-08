#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int n, m, a, b;

int main() {
    cin >> n >> m;
    vector<int> g[n]; set<int> s[n]; vector<pair<int, int>> t;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        cin >> a;
        a--;
        t.push_back({a, i});
    }
    sort(t.begin(), t.end());
    vector<int> ans;
    bool ff = false;
    for(const auto &ti: t){
        int ac = 0;
        while(!s[ti.second].empty() && s[ti.second].find(ac) != s[ti.second].end()) ac++;
        
        if(ac != ti.first){
           
            ff = true;
            break;
        }
        for(int &v: g[ti.second])
            s[v].insert(ti.first);
        ans.push_back(ti.second + 1);
    }
    if(ff){
        cout << -1 << endl;
        return 0;
    }
    for(const int &e: ans) cout << e << " ";
    cout << endl;
    return 0;
}