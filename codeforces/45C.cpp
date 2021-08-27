# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

typedef tuple<int, int, int> couple;
const int MAXN = 2e5 + 5;
int a[MAXN], N;
string line;

class Compare{
public:
    bool operator()(couple &c1, couple & c2){
        if(get<0>(c1) < get<0>(c2)) return false;
        else if(get<0>(c1) > get<0>(c2)) return true;
        else return get<1>(c1) > get<1>(c2);
    }    
};

int main(){
    io_boost;
    priority_queue<couple, vector<couple>, Compare> pq;
    cin >> N >> line;
    for(int i = 0; i < N; i++) cin >> a[i];
    set<int> av;
    for(int i = 0; i < N - 1; i++)
        if(line[i] != line[i + 1])
            pq.push({abs(a[i] - a[i + 1]), i, i + 1});
    for(int i = 0; i < N; i++) av.insert(i);
    vector<pair<int, int>> ans;
    while(!pq.empty()){
        auto [d, i, j] = pq.top();
        pq.pop();
        if(!av.count(i) || !av.count(j)) continue;
        ans.push_back({i, j});
        av.erase(i);
        av.erase(j);

        auto it = av.lower_bound(i);
        if(it == av.begin()) continue;
        it--;
        i = *it;

        it = av.lower_bound(j);
        if(it == av.end()) continue;
        j = *it;

        if(i == -1 || j == N) continue;
        if(line[i] != line[j]) pq.push({abs(a[i] - a[j]), i, j});
    }
    cout << ans.size() << endl;
    for(auto [i, j] : ans)
        cout << i + 1 << " " << j + 1 << endl;
    return 0;
}