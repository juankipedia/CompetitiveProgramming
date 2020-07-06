#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int t;
int n, k;

 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        lli m[n][n] = {};
        for(int i = 0; i < n && k; i++)
            for(int j = 0; j < n && k; j++)
                m[j][(i + j) % n] = 1, k --;

        int maxi = 0, mini = n * n;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++) sum += m[i][j];
            maxi = max(maxi, sum);
            mini = min(mini, sum);
        }
        int ans = (maxi - mini) * (maxi - mini);
        maxi = 0; mini = n * n;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++) sum += m[j][i];
            maxi = max(maxi, sum);
            mini = min(mini, sum);
        }
        ans += (maxi - mini) * (maxi - mini);
        cout << ans << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cout << m[i][j];
            cout << endl;
        }

    }
    return 0;
}