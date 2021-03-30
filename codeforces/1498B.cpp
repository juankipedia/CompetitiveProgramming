# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N, W, w[100005];

int main(){
    cin >> t;
    while(t--){
        cin >> N >> W;
        map<int, int, greater<int>> m;
        for(int i = 0; i < N; i++) cin >> w[i], m[w[i]]++;
        int H = 0;
        while(!m.empty()){
            int Wi = W;
            vector<int> d;
            for(auto &[p, f] : m){
                int cnt = Wi / p;
                Wi -= min(cnt, f) * p;
                f -= min(cnt, f);
                //cout << "+++" << p << " " << f << endl;
                if(!f) d.push_back(p);
                if(Wi == 0) break;
            }
            for(int e: d){
                //cout << "----" << e << endl;
                m.erase(e);
            }
            H++;
        }
        cout << H << endl;

    }


    return 0;
}