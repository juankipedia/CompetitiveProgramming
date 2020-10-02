#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<lli, int> pair_l;
const lli oo = numeric_limits<lli>::max();

int n, ti;
lli x[200], y[200], g[200][200];

bool dp(int i, lli dist, bool v[]){
    if(i == 1) return true;
    v[i] = true;
    bool ans = false;
    for(int j = 0; j < n; j++)
        if(!v[j] && g[i][j] <= dist) ans = ans  || dp(j, dist, v);
    return ans;
}

int main(){
    io_boost;
    ti = 1;
    while(cin >> n && n != 0){
        for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
        vector<lli> distances;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    g[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                    distances.push_back(g[i][j]);
                }
                else g[i][j] = 0;
            }
        }

        sort(distances.begin(), distances.end());
        int lo = 0, hi = distances.size() - 1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            bool v[n] = {false};
            if(dp(0, distances[mid], v))
                hi = mid;
            else
                lo = mid + 1;
        }

        cout << "Scenario #" << ti << endl;
        cout << "Frog Distance = ";
        cout << std::fixed;
        cout << std::setprecision(3) << sqrt(distances[lo]) << endl << endl;
        ti++;
    }
    return 0;
}