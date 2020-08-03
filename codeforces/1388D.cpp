#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, b[200000];
bool visited[200000];
stack<int> ts, nr;
vector<int> pr;
lli ans, a[200000];


void topo_sort(int v){
    if(visited[v]) return;
    visited[v] = true;
    if(b[v] != -1)
        topo_sort(b[v]);
    ts.push(v);
}

void topo_sort(){
    for(int i = 0; i < n; i++)
        if(!visited[i])
            topo_sort(i);
    while(!ts.empty()){
        if(a[ts.top()] >= 0){
            pr.push_back(ts.top() + 1);
            if(b[ts.top()] != -1)
                a[b[ts.top()]] += a[ts.top()];
            ans += a[ts.top()];
        }
        else{
            ans += a[ts.top()];
            nr.push(ts.top());
        }
        ts.pop();
    }
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> b[i];
        if(b[i] != -1)
            b[i]--;
    }
    topo_sort();
    cout << ans << endl;
    for(const int &p: pr) cout << p << " ";
    while(!nr.empty()){
        cout << nr.top() + 1 << " ";
        nr.pop();
    }
    cout << endl;
    return 0;
}