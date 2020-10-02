#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<lli, int> pair_l;
typedef pair<pair<lli, lli>, int> pp;

const lli oo = numeric_limits<lli>::max();
int N, T, R, U, V;
lli W, SD;

lli sp(vector<pair_l> g[], bool asp = false){
    vector<pair<lli, lli>> d(N, {oo, oo});
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    d[0] = {0, oo};
    pq.push({d[0], 0});

    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        U = p.second;
        lli best = p.first.first;
        lli sbest = p.first.second;
        for(pair_l &pp : g[U]){
            V = pp.second;
            W = pp.first;

            set<lli> pd;
            if(best != oo) pd.insert(best + W);
            else pd.insert(oo);
            if(sbest != oo) pd.insert(sbest + W);
            else pd.insert(oo);
            pd.insert(d[V].first); pd.insert(d[V].second);
            auto it = pd.begin();
            lli nbest = *it;
            it++;
            lli nsbest = *it;
            if(d[V].first > nbest || d[V].second > nsbest){
                d[V].first = nbest;
                d[V].second = nsbest;
                pq.push({d[V], V});
            }

        }
    }
    return d[N - 1].second;
}

int main(){
    io_boost;
    cin >> T;
    for(int ti = 1; ti <= T; ti++){
        cin >> N >> R;
        vector<pair_l> g[N];
        for(int i = 0; i < R; i++){
            cin >> U >> V >> W;
            U--; V--;
            g[U].push_back({W, V});
            g[V].push_back({W, U});
        }

        cout << "Case " << ti << ": " << sp(g) << endl;
    }
    return 0;
}