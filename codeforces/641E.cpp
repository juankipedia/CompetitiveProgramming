#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const int MAXN = 1e5;
int n;
struct query{
    short a;
    lli t, x;
    int idx;
};
 
query q[MAXN];
vector<query> m[MAXN];
 

int id[MAXN]; // id to map each element of a
 
int ans[MAXN];
 
 
struct FenwickTree{
    map<int, int> bit;
    int N = 1e9;
    lli sum(int r){
        lli ret = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
 
    void add(lli val, int i){
        for(; i < N; i = i | (i + 1))
            bit[i] += val;
    }
};
 
 
int main(){
    io_boost;
    cin >> n;
    map<lli, int> mm;
    int curm = 0;
    for(int i = 0; i < n; i++){
        cin >> q[i].a >> q[i].t >> q[i].x;
        q[i].idx = i;
        if(!mm.count(q[i].x))
            mm[q[i].x] = curm++;
        m[mm[q[i].x]].push_back(q[i]);
    }
        
    for(int i = 0; i < curm; i++){
        FenwickTree tree;    
        for(auto &qq: m[i]){
            if(qq.a == 1) tree.add(1, qq.t);
            else if(qq.a == 2) tree.add(-1, qq.t);
            else ans[qq.idx] = tree.sum(qq.t);
        }
    }
 
    for(int i = 0; i < n; i++)
        if(q[i].a == 3) cout << ans[i] << endl;
 
    return 0;
}