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
typedef pair<lli, lli> pl;
 

 
pl intersect(pl a, pl b){
    if(a.first > b.second || b.first > a.second){
        return {0, -1};
    }
    return {max(a.first, b.first), min(a.second, b.second)};
}

pl expand(pl pr, lli x){
    lli a = pr.first;
    lli b = pr.second;
    return {a-x, b+x};
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n;
        lli m;
        cin >> n >> m;
        pl start = {m, m};
        lli time = 0;
        bool fails = false;
        for(int j = 0; j < n; j++){
            lli t, l, h;
            cin >> t >> l >> h;
            start = intersect(expand(start, t - time), {l, h});
            time = t;
            if(start.first == 0 && start.second == -1){
                fails = true;
            }
        }
        if(fails){
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}
