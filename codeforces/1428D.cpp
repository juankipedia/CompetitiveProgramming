# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;
int n, a[MAXN];

struct Target{
    int i, j, r;
};


int main(){
    io_boost;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    stack<int> s3, s2;
    int r = 0;
    vector<Target> ans;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) continue;
        if(a[i] == 1){
            int j = -1;
            if(!s2.empty()){
                j = s2.top();
                s2.pop();
            }
            else if(!s3.empty()){
                j = s3.top();
                s3.pop();
            }
            ans.push_back({j, i, r});
            if(j != -1 && a[j] == 3) r++;
            r++;
        }
        else if(a[i] == 2){
            if(!s3.empty()){
                int j = s3.top();
                s3.pop();
                ans.push_back({j, i, r});
                r++;
            }
            s2.push(i);
        }
        else{
            if(!s3.empty()){
                int j = s3.top();
                s3.pop();
                ans.push_back({j, i, r});
                r ++;
            }
            s3.push(i);
        }   
    }
    if(!s2.empty() || !s3.empty()){
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> res;

    for(const auto &t : ans){
        if(t.i == -1) res.emplace_back(t.r + 1,  t.j + 1);
        else if(a[t.i] == 3){
            res.emplace_back(t.r + 1, t.i + 1);
            res.emplace_back(t.r + 1, t.j + 1);
            if(a[t.j] == 1) res.emplace_back(t.r + 2, t.j + 1);
        }
        else{
            res.emplace_back(t.r + 1, t.i + 1);
            res.emplace_back(t.r + 1, t.j + 1);
        }
    }
    cout << res.size() << endl;
    for(auto &p : res) cout << p.first << " " << p.second << endl;
    return 0;
}
