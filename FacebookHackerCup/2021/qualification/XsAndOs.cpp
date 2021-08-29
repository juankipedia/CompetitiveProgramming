# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int T, N;
string m[2005];

int main(){
    io_boost;
    cin >> T;
    for(int ti = 1; ti <= T; ti++){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> m[i];
        int mini = 1e9;
        for(int i = 0; i < N; i++){
            int need = 0;   
            for(int j = 0; j < N; j++)
                if(m[i][j] == '.') need++;
                else if(m[i][j] == 'O'){
                    need = 1e9;
                    break;
                }
            mini = min(need, mini);
        }
        for(int i = 0; i < N; i++){
            int need = 0;   
            for(int j = 0; j < N; j++)
                if(m[j][i] == '.') need++;
                else if(m[j][i] == 'O'){
                    need = 1e9;
                    break;
                }
            mini = min(need, mini);
        }
        cout << "Case #" << ti << ": ";
        if(mini == 1e9){
            cout << "Impossible" << endl;
            continue;
        }
        set<set<pair<int, int>>> ans;
        for(int i = 0; i < N; i++){
            set<pair<int, int>> v;
            for(int j = 0; j < N; j++)
                if(m[i][j] == '.') v.insert({i, j});
                else if(m[i][j] == 'O'){
                    v.clear();
                    break;
                }
            if(v.size() == mini) ans.insert(v);
        }
        for(int i = 0; i < N; i++){
            set<pair<int, int>> v;
            for(int j = 0; j < N; j++)
                if(m[j][i] == '.') v.insert({j, i});
                else if(m[j][i] == 'O'){
                    v.clear();
                    break;
                }
            if(v.size() == mini) ans.insert(v);
        }
        cout << mini << " " << ans.size() << endl;

    }
    return 0;
}