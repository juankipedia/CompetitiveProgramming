# include <iostream>
# include <stdio.h>
# include <fstream>
# include <string.h>
# include <string>
# include <vector>
# include <map>
# include <set>
# include <list>
# include <set>
# include <deque>
# include <utility>
# include <sstream>
# include <queue>
# include <stack>
# include <bitset>
# include <math.h>
# include <algorithm>
# include <limits.h>
# include <iomanip>
# include <numeric> 
# include <functional>
# include <cstdlib>
# include <ctime>

using namespace std;

# define endl "\n"
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

void build(int u, int i, int &nodes, string &ts, vector<int> t[], int p[]){
    if(i >= ts.size()) return;
    if(ts[i] == '0'){
        int v = nodes;
        t[u].push_back(v);
        t[v].push_back(u);
        nodes++;
        p[v] = u;
        build(v, i + 1, nodes, ts, t, p);
    }
    else build(p[u], i + 1, nodes, ts, t, p);
}

ulli rand_uint64_slow() {
  ulli r = 0;
  for (int i = 0; i < 60; i++) r = r * 2 + rand() % 2;
  return r;
}

map<ulli, ulli> hash_map;
ulli g(ulli x){
    if(hash_map.count(x)) return hash_map[x];
    else return hash_map[x] = rand_uint64_slow();
}

ulli get_hash(int u, int p, vector<int> t[]){
    ulli hash_sum = 0;
    for(int v = 0; v < t[u].size(); v++)
        if(t[u][v] != p)
            hash_sum += get_hash(t[u][v], u, t);
    return g(hash_sum); 
}

int main(){
    int t;
    cin >> t;
    while (t--){
        string t1s, t2s;
        cin >> t1s >> t2s;
        int nodes1 = 1;
        int nodes2 = 1;
        vector<int> t1[3010], t2[3010];
        int p1[3010], p2[3010];
        build(0, 0, nodes1, t1s, t1, p1);
        build(0, 0, nodes2, t2s, t2, p2);
        if(get_hash(0, -1, t1) == get_hash(0, -1, t2)) cout << "same" << endl;
        else cout << "different" << endl;
    }
    
    return 0;
}