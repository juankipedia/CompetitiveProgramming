#include <bits/stdc++.h>
using namespace std;
 
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
 
 
 
 
 
 
 
bool multiple(string &g, string &s){
    bool ok = true;
    for(int i = 0; i < s.size(); i++){
        if(g[i % g.size()] != s[i]){
            ok = false;
            break;
        }
    }
    if(!ok){
        return false;
    }
    else{
        return (s.size() % g.size()) == 0;
    }
}
 
int main(){
    io_boost;
    int t;
string S, T, current;
    cin >> t;
    while(t--){
        cin >> S >> T;
        if(S.size() > T.size()) swap(S, T);
        bool found = false;
        for(int i = 0; i < S.size(); i++){
            string g = S.substr(0, i + 1);
            if(multiple(g, S) && multiple(g, T)){
                found = true;
                current = g;
                while (!multiple(S, current) || !multiple(T, current)){
                    current += g;
                }
                break;
            }
        }
        if(!found){
            cout << -1 << '\n';
        }
        else{
            cout << current << '\n';
        }
    }
    
    return 0;
}