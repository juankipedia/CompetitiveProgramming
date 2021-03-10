# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 100005;
int t, n;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        vector<lli> miner, diamond;
        for(int i = 0, x, y; i < n * 2; i++){
            cin >> x >> y;
            if(x == 0) miner.push_back(abs(y));
            else diamond.push_back(abs(x));
        }
        sort(miner.begin(), miner.end());
        sort(diamond.begin(), diamond.end());

        long double ans = 0;
        for(int i = 0; i < n; i++){
            //cout << miner[i] << " " << diamond[i] << endl;
            ans += sqrt(miner[i] * miner[i] + diamond[i] * diamond[i]);
        }
        cout << std::fixed << setprecision(15) << ans << endl;
    }
    return 0;
}