#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e6 + 5;
int N, Q, pre[MAXN], nxt[MAXN];
lli t[MAXN];
struct Query{ int l, r, idx; };
Query q[MAXN];
vector<pair<int, bool>> intervals[MAXN];

struct FenwickTree{
    vector<lli> bit;
    int N;
    FenwickTree(int n){
        N = n;
        bit.assign(N, 0);
    }

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
    cin >> N;
    for(int i = 0; i < N; i++) cin >> t[i];
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> q[i].l >> q[i].r;
        q[i].l--; q[i].r--;
        q[i].idx = i;
    }
    map<lli, int> pos;
    for(int i = 0; i < N; i++) pos[t[i]] = -1;
    for(int i = 0; i < N; i++){
        pre[i] = pos[t[i]];
        pos[t[i]] = i;
    }

    for(int i = 0; i < N; i++) pos[t[i]] = N;
    for(int i = N - 1; i >= 0; i--){
        nxt[i] = pos[t[i]];
        pos[t[i]] = i;
    }

    for(int i = 0; i < N; i++){
        intervals[pre[i] + 1].push_back({nxt[i], true});
        intervals[pre[i] + 1].push_back({i, false});
        intervals[i + 1].push_back({nxt[i], false});
    }
    
    sort(q, q + Q, [](auto &q1, auto &q2){return q1.l < q2.l; });
    FenwickTree tree(N + 1);
    int j = 0;
    int ans[Q];
    for(int l = 0; l < N; l++){
        for(auto &ub: intervals[l]){
            if(ub.second) tree.add(1, ub.first);
            else tree.add(-1, ub.first);
        }
        
        while(j < Q && q[j].l == l){
            ans[q[j].idx] = tree.sum(N) - tree.sum(q[j].r);
            j++;
            
        }
    }

    for(int i = 0; i < Q; i++) cout << ans[i] << endl;
    return 0;
}