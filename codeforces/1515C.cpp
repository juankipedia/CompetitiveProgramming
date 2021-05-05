# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m, x, h[100005];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m >> x;
        for(int i = 0; i < n; i++) cin >> h[i];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < m; i++) pq.push({0, i});
        int d[m] = {0}, ans[n];
        for(int i = 0; i < n; i++){
            auto [hj, j] =  pq.top();
            pq.pop();
            d[j] = hj + h[i];
            ans[i] = j + 1;
            pq.push({d[j], j});
        }
        int mini = pq.top().first;
        bool ok = true;
        for(int i = 0; i < m; i++)
            if(abs(d[i] - mini) > x) ok = false;
        if(ok){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) cout << ans[i] << " ";
            cout << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}