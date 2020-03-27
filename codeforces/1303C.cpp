# include <bits/stdc++.h>

using namespace std;
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int INF = std::numeric_limits<int>::max();
typedef unsigned long long int ulli;

int t, m, n;
string s;

void print_adjacent(int p, int i, vector<int> g[]){
    if(i == -1) return;
    cout << static_cast<char>(i + 'a');
    if(g[i][0] != p) print_adjacent(i, g[i][0], g);
    else print_adjacent(i, g[i][1], g);
}

void print_keyboard(vector<int> g[]){
    int j = -1;
    for(int i = 0; i < 26; i++) if(g[i].size() == 1){
        g[i].push_back(-1);
        j = i;
    }
    print_adjacent(-1, j, g);
    for(int i = 0; i < 26; i++) if(g[i].size() == 0) cout << static_cast<char>(i + 'a');
    cout << "\n";
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> s;
        vector<int> g[26];
        bool bad = false;
        bool map[26] = {false};
        n = 0;
        m = 0;
 
        for(int i = 1; i < s.size(); i++){
            int u = s[i] - 'a', v = s[i - 1] - 'a';
            map[u] = true;
            map[v] = true;
            if(g[u].size() == 1 && g[u][0] == v) continue;
            else if(g[u].size() == 2 && (g[u][1] == v || g[u][0] == v)) continue;
            else if(g[u].size() < 2 && g[v].size() < 2){
                g[u].push_back(v); g[v].push_back(u);
                m++;
            }
            else{
                cout << "NO" << "\n";
                bad = true;
                break;
            }
        }

        if(bad) continue;
        
        for(int i = 0; i < 26; i++) if(map[i]) n++;
        if(n == 0) n = 1;
        if((n - 1) != m){
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << endl;
        print_keyboard(g);
    }    
    return 0;
}