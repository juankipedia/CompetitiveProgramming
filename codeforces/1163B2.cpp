# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;
int N, u[MAXN];

map<int, int> m1;
map<int, set<int>> m2;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> u[i];
    int x = 1;
    for(int i = 0; i < N; i++){
        if(!m1.count(u[i])){
            m1[u[i]] = 1;
            m2[1].insert(u[i]);
        }
        else{
            m2[m1[u[i]]].erase(u[i]);
            if(m2[m1[u[i]]].size() == 0) m2.erase(m1[u[i]]);
            m1[u[i]]++;
            m2[m1[u[i]]].insert(u[i]);
        }
        if(m2.size() > 2) continue;
        else{
            if(m2.size() == 1 && (m2.begin()->first == 1 || m2.begin()->second.size() == 1)){
                x = i + 1;
            }
            if(m2.begin()->first == 1 && m2.begin()->second.size() == 1){
                x = i + 1;
            }
            if(m2.size() == 2 && (m2.begin()->first + 1) == m2.rbegin()->first && m2.rbegin()->second.size() == 1){
                
                x = i + 1;
            }
        }
    }
    cout << x << endl;
    return 0;
}