#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<lli, int> pair_l;
const int oo = numeric_limits<int>::max();

int t, R, C, ti;

string m[1000];
int dist[1000][1000];
int ii[] = {1, -1, 0, 0}, ij[] = {0, 0, 1, -1};


int main(){
    io_boost;
    cin >> t;
    for(ti = 1; ti <= t; ti++){
        cin >> R >> C;
        for(int i = 0; i < R; i++) cin >> m[i];
        
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                dist[i][j] = oo;
    
        deque<int> qi;
        deque<int> qj;
        dist[0][0] = 0; 
        qi.push_back(0); 
        qj.push_back(0);
        while (!qi.empty()){ 
            int i = qi.front(), j = qj.front(); 
            qi.pop_front(); qj.pop_front();
            for (int k = 0; k < 4; k++){
                int ni = i + ii[k], nj = j + ij[k];
                if(ni >= 0 && ni < R && nj >= 0 && nj < C){
                    int w = (m[i][j] == m[ni][nj]) ? 0 : 1;
                    if(dist[ni][nj] > dist[i][j] + w){ 
                        dist[ni][nj] = dist[i][j] + w; 
                        if(w == 0){
                            qi.push_front(ni);
                            qj.push_front(nj);
                        }
                        else{
                            qi.push_back(ni);
                            qj.push_back(nj);
                        }
                    }
                }
            } 
        } 
        cout << dist[R - 1][C - 1] << endl;
    }
    

    return 0;
}