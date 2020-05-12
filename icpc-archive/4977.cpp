#include <bits/stdc++.h>
using namespace std;

# define endl "\n"

int t[1000000], p[1000001], ans[1000000], T, N, M;

set<pair<int, int>> :: iterator it;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        
        for(int i = 0; i < M; ++i) cin >> t[i];
        
        set<pair<int, int>> s;
        int cont = 0;
        bool f = false;
        memset(p, -1, sizeof p);
        
        for(int i = 0;i < M;++i){
            if(t[i] == 0){
                ans[cont] = 0;
                s.insert(make_pair(i, cont++));
            }else{
                it = s.lower_bound(make_pair(p[ t[i] ],0));
                
                if(it == s.end()){f = true; break;}
                else{
                    ans[it->second] = t[i];
                    p[t[i]] = i;
                    s.erase(it);
                }
            }
        }
        
        if(f) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            for(int i = 0;i < cont;++i){
                if(i) cout << " ";
                cout << ans[i];
            }
            cout << endl;
        }
    }
    
    return 0;
}