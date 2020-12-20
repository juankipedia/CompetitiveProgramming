#include <bits/stdc++.h>
using namespace std;
# define endl '\n'
# define fast_io std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> pii;

int main(){
    int t, n, m, x[100000], y[100000];
    map<int, int> mm;
    fast_io;
    cin >> t;
    while (t--){
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            cin >> x[i] >> y[i];
            if(x[i] != y[i]){
                mm[x[i]] = y[i];
            }
        }
        int res = 0;
        set<pii> path;
        bool ok;
        while(true){
            if(!mm.size()){
                break;
            }
            pii p = *mm.begin();
            path.clear();
            path.insert(p);
            ok = false;
            while(true){
                if(!mm.count(p.second)){ 
                    break; 
                }
                p = {p.second, mm[p.second]};
                if(path.count(p)){
                    ok = true;
                    break;
                }
                path.insert(p);

            }
            if(ok){
                res += path.size() + 1;
            }
            else{ 
                res += path.size();
            }
            for(auto &par: path){
                mm.erase(par.first);
            }
        }
        cout << res << endl;
    }
    
    return 0;
}