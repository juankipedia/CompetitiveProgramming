#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;


int t;
ulli n, k, a[200000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        priority_queue< pair<ulli, ulli>, vector <pair<ulli, ulli>> , greater<pair<ulli, ulli>> > que;
        map<ulli, ulli> m;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            if(a[i] % k == 0) ++m[0];
            else ++m[k - a[i] % k];
        }
        for(const auto &p: m)
            if(p.first != 0)
                que.push(p);
           
        if(que.empty()){
            cout << 0 << endl;
            continue;
        }

        ulli x = 0, ans = 0;
        while(!que.empty()){
            auto p = que.top();
            que.pop();
            if(p.first == x){
                x++;
                ans++;
                p.second--;
            }
            else{
                ans += p.first - x + 1;
                x = p.first + 1;
                p.second--;
            }
            if(p.second)
                que.push({p.first + k, p.second});
        }
        cout << ans << endl;

    }
    return 0;
}