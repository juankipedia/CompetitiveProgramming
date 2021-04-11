# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string m[500];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> m[i];

        vector<pair<int, int>> a;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(m[i][j] == '*')
                    a.push_back({i, j});

        if(a[0].first == a[1].first){
            if(a[0].first == 0){
                m[a[0].first + 1][a[0].second] = '*';
                m[a[1].first + 1][a[1].second] = '*';
            }
            else{
                m[a[0].first - 1][a[0].second] = '*';
                m[a[1].first - 1][a[1].second] = '*';
            }
        }
        else if(a[0].second == a[1].second){
            if(a[0].second == 0){
                m[a[0].first][a[0].second + 1] = '*';
                m[a[1].first][a[1].second + 1] = '*';
            }
            else{
                m[a[0].first][a[0].second - 1] = '*';
                m[a[1].first][a[1].second - 1] = '*';
            }
        }
        else if(m[min(a[0].first, a[1].first)][min(a[0].second, a[1].second)] == '*'){
            m[min(a[0].first, a[1].first)][max(a[0].second, a[1].second)] = '*';
            m[max(a[0].first, a[1].first)][min(a[0].second, a[1].second)] = '*';
        }
        else{
            m[min(a[0].first, a[1].first)][min(a[0].second, a[1].second)] = '*';
            m[max(a[0].first, a[1].first)][max(a[0].second, a[1].second)] = '*';
        }
   
        for(int i = 0; i < n; i++)
            cout << m[i] << endl;
    }
    return 0;
}