# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

vector<pair<int, int>> xy;

bool check(lli k){
    queue<pair<lli, lli>> q;
    lli mini = numeric_limits<lli>::max(), maxi = 0;
    for(auto &[xi, yi]: xy){
        while(!q.empty()){
            if(q.front().first > (xi - k) && q.front().first < (xi + k)) break;
            mini = min(mini, q.front().second); maxi = max(maxi, q.front().second);
            q.pop();
        }
        if(mini <= yi - k || maxi >= yi + k) return true;
        q.push({xi, yi});
    }
    return false;
}

int main(){
    io_boost;
    int N;
    cin >> N;
    xy.assign(N, make_pair(0, 0));
    for(int i = 0; i < N; i++) cin >> xy[i].first >> xy[i].second;
    lli lo = 0, hi = 1e15;
    sort(xy.begin(), xy.end());
    while(lo < hi){
        lli mid = (lo + hi + 1) / 2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
    return 0;
}