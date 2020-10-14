#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N;


int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> N;
        int w = N;
        vector<pair<int, int>> ans;
        for(int i = N - 1; i >= 1; i--){
            ans.push_back({w, i});
            if((w + i) % 2) w = 1 + (w + i) / 2;
            else w = (w + i) / 2;
        }
        cout << w << endl;
        for(auto &p: ans) cout << p.first << " " << p.second << endl;
    }
    return 0;
}