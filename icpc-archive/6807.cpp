#include <bits/stdc++.h>
using namespace std;

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

int T, Ti, S, L, u, v, c;

int find(int p[], int i){
    if(p[i] != i)
        p[i] = find(p, p[i]);
    return p[i];
}

void join(int p[], int x, int y){
    int yr = find(p, y), xr = find(p, x);
    p[xr] = yr;
}

void k(vector<pair<int, pair<int, int>>> &edges){
    int p[S + 1];
    for(int i = 1; i <= S; i++) p[i] = i;
    sort(edges.begin(), edges.end(), std::greater<pair<int, pair<int, int>>>());
    int e = 0, i = 0, maxi = 0, ans = 0;
    bool edgesMst[L] = {false};
    while(e < S - 1){
        c = edges[i].first;
        u = find(p, edges[i].second.first); 
        v = find(p, edges[i].second.second);
        if(u != v){
            join(p, u, v);
            edgesMst[i] = true;
            e++;
        }
        i++;
    }
    for(int i = 0; i < L; i++){
        if(!edgesMst[i]){
            maxi = max(maxi, edges[i].first);
            ans += edges[i].first;
        }
    }
    cout << ans << " " << maxi << endl;
}

int main() {
    io_boost;
    cin >> T;
    for(Ti = 1; Ti <= T; Ti ++){
        cin >> S >> L;
        cout << "Case #" << Ti << ": ";
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < L; i++){
            cin >> u >> v >> c;
            edges.push_back({c, {u, v}});
        }
        k(edges);
    }
    return 0;
}