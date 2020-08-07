#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, w[50];
bool m[100 + 1][50];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> w[i];
        for(int i = 0; i <= (2 * n); i ++)
            for(int j = 0; j < n; j ++)
                m[i][j] = false;
        
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(!m[w[i] + w[j]][i] && !m[w[i] + w[j]][j])
                    m[w[i] + w[j]][i] = m[w[i] + w[j]][j] = true;
        int ans = 0;
        for(int i = 0; i <= (2 * n); i ++){
            int s = 0;
            for(int j = 0; j < n; j ++)
                if(m[i][j]) s++;
            ans = max(s / 2, ans);
        }
        cout << ans << endl;
    }
    return 0;
}