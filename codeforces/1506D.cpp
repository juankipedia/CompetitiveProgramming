# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n, a[200007];
 
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        map<int, int> m;
        for(int i = 0; i < n; i++) cin >> a[i], m[a[i]]++;
        priority_queue<pair<int, int>> pq;
        for(auto &[a, b]: m) pq.push({b, a});
        while(pq.size() >= 2){
            auto [a, b] = pq.top();
            pq.pop();
            auto [c, d] = pq.top();
            pq.pop();
            a--;
            c--;
            n -= 2;
            if(a) pq.push({a, b});
            if(c) pq.push({c, d});
        }
        cout << n << endl;
    }
    return 0;
}
