#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[200005], b[200005];
lli m;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        lli sum = 0;
        for(int i = 0; i < n; i++) cin >> a[i], sum += a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        if(sum < m){
            cout << -1 << endl;
            continue;
        }
        vector<int> one, two;
        for(int i = 0; i < n; i++){
            if(b[i] == 1) one.push_back(a[i]);
            else two.push_back(a[i]);
        }
        sort(two.begin(), two.end());
        sort(one.begin(), one.end());
        int ans = 0;
        while(m > 0){
            if(one.size() == 0){
                m -= two[two.size() - 1];
                two.pop_back();
                ans += 2;
                continue;
            }
            if(two.size() == 0){
                m -= one[one.size() - 1];
                one.pop_back();
                ans += 1;
                continue;
            }
            if(one[one.size() - 1] >= m){
                m -= one[one.size() - 1];
                one.pop_back();
                ans += 1;
                continue;
            }
            
            if(one.size() > 1){
                if((one[one.size() - 1] + one[one.size() - 2]) > two[two.size() - 1]){
                    ans += 1;
                    m -= one[one.size() - 1];
                    one.pop_back();
                    continue;
                }
            }
            ans += 2;
            m -= two[two.size() - 1];
            two.pop_back();
        }

        cout << ans << endl;
        
    }
    
    return 0;
}