# include <bits/stdc++.h>
using namespace std;
    
#define V 94 
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

ulli INF = std::numeric_limits<ulli>::max();
ulli graph[V][V];
ulli dist[V][V];

void f_w(){
  int i, j, k;
  for (i = 0; i < V; ++i)
    for(j = 0; j < V; ++j)
      dist[i][j] = graph[i][j];

  for (k = 0; k < V; ++k)
    for(i = 0; i < V; ++i)
        for (j = 0; j < V; ++j)
          if(dist[i][k] != INF and dist[k][j] != INF and dist[i][k] + dist[k][j] < dist[i][j])
            dist[i][j] = dist[i][k] + dist[k][j];
}


int main(){
  string s, t;
  cin >> s;
  cin >> t;
  ulli m, w;
  cin >> m;
  char src, tg;
  for (int i = 0; i < V; ++i)
    for(int j = 0; j < V; ++j)
        if(i == j)
          graph[i][j] = 0;
        else
          graph[i][j] = INF;  


  for (ulli i = 0; i < m; ++i){
    cin >> src >> tg >> w;
    if(graph[src - 33][tg - 33] == INF)
      graph[src - 33][tg - 33] = w;
    else
      graph[src - 33][tg - 33] = min(graph[src - 33][tg - 33], w);
  }
  ulli r = 0, c;

  f_w();



  for (ulli i = 0; i < s.length(); ++i){
    if(s[i] != t[i]){
      c = dist[s[i] - 33][t[i] - 33];
      if(c == INF){
        cout << -1 << endl;
        return 0;
      }
      else
        r += c;
    }
  }
  cout << r << endl;
  return 0; 
} 
