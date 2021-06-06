# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

struct op{
    int type, i, j;
};

int T, N, a[1005];

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> a[i];
        vector<op> ans;
        for(int i = 0; i < N / 2; i++){
            int j = N - 1 - i;
            //cout << a[i] << " " << a[j] << endl;
            ans.push_back({1, i, j});
            
            ans.push_back({2, i, j});
        
            ans.push_back({1, i, j});
            
            ans.push_back({2, i, j});
            
            ans.push_back({1, i, j});

            ans.push_back({2, i, j});
            // a[i] += a[j];

            // cout << a[i] << " " << a[j] << endl;
        }
        cout << ans.size() << endl;
        for(auto &e : ans){
            cout << e.type << " " << e.i + 1  << " " << e.j + 1 << endl;
        }
    }
    return 0;
}