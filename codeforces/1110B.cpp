# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m, k, b[100000];

int main(){
    cin >> n >> m >> k;
    int ki = n;
    for(int i = 0; i < n; i++) cin >> b[i];
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i < n; i++)
        pq.push(b[i] - b[i - 1]);
    lli ans = 0;
    while(ki > k && !pq.empty()){
        ans += pq.top();
        pq.pop();
        ki--;
    }
    cout << ans + ki << endl;
    return 0;
}