# include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

void query(int v){ cout << "? " << v << endl; }
int n;
set<int> g[2005];

int main(){
    cin >> n;
    query(1);
    int d[n + 5];
    for(int i = 1; i <= n; i++){
        cin >> d[i];
        if(d[i] == 1) g[1].insert(i), g[i].insert(1);
    }
    vector<int> r, b;
    for(int i = 1; i <= n; i++)
        if(d[i] % 2) r.push_back(i);
        else b.push_back(i);
    if(r.size() < b.size()) swap(r, b);
    for(int v: b){
        if(v == 1) continue;
        query(v);
        for(int i = 1; i <= n; i++){
            cin >> d[i];
            if(d[i] == 1) g[v].insert(i), g[i].insert(v);
        }
    }
    cout << "!" << endl;
    for(int i = 1; i <= n; i++){
        for(int v: g[i]){
            cout << i << " " << v << endl;
            g[v].erase(i);
        }
    }
    return 0;
}