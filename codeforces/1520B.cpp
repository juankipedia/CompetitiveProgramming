# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= 9; i++){
            string nn = "";
            nn += i + '0';
            while(stoll(nn) <= n){
                ans++;
                nn += i + '0';
            }
        }
        cout << ans << endl;
    }
    return 0;
}