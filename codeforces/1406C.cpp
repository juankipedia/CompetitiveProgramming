#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, U, V, cnt[100000];

int dfs(vector<int>g[], int node, int parent){
    int maxi = 0, sum = 1;
    for(const int &child: g[node]){
        if(child == parent) continue;
        int d = dfs(g, child, node);
        sum += d;
        maxi = max(d, maxi);
    }
    maxi = max(maxi, n - sum);
    cnt[node] = maxi;
    return sum;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> g[n];
        for(int i = 0; i < n - 1; i++){
            cin >> U >> V;
            U--; V--;
            g[U].push_back(V);
            g[V].push_back(U);
        }
        dfs(g, 1, -1);
        int mini = 100000, c1 = -1, c2 = -1;
        for(int i = 0; i < n; i++) mini = min(cnt[i], mini);
        for(int i = 0; i < n; i++)
            if(cnt[i] == mini && c1 == -1) c1 = i;
            else if(cnt[i] == mini && c1 != -1) c2 = i;
        
        if(c1 != -1 && c2 == -1){
            cout << c1 + 1 << " " << g[c1][0] + 1 << endl;
            cout << c1 + 1 << " " << g[c1][0] + 1 << endl;
        }
        else{
            int in = 0;
            if(g[c2][in] == c1) in++;
            cout << c2 + 1 << " " << g[c2][in] + 1 << endl;
            cout << c1 + 1 << " " << g[c2][in] + 1 << endl;
        } 
    }
    return 0;
}