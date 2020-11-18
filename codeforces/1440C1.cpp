
#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n, m;
string ma[100];
int ii[] = {0, 0, 1, 1}, ji[] = {0, 1, 0, 1};
void change(pair<int, int> &p){
    int i = p.first - 1, j = p.second - 1;
    if(ma[i][j] == '0') ma[i][j] = '1';
    else ma[i][j] = '0';
}
 
void process3(vector<pair<int, int>> &z, vector<pair<int, int>> &o, vector<pair<int, int>> &ans){
        
    for(auto &p: o){
        ans.push_back(p);
        change(p);
    }
}
 
void process2(vector<pair<int, int>> &z, vector<pair<int, int>> &o, vector<pair<int, int>> &ans){
 
    ans.push_back(o[1]);
    change(o[1]);
    ans.push_back(z[0]);
    change(z[0]);
    ans.push_back(z[1]);
    change(z[1]);
    auto z0 = z[0], z1 = z[1];
    z.pop_back(); z.pop_back();
    z.push_back(o[1]);
    o.pop_back();
    o.push_back(z0); o.push_back(z1);  
 
    process3(z, o, ans);  
}
 
void process1(vector<pair<int, int>> &z, vector<pair<int, int>> &o, vector<pair<int, int>> &ans){
 
    ans.push_back(o[0]);
    change(o[0]);
    ans.push_back(z[1]);
    change(z[1]);
    ans.push_back(z[2]);
    change(z[2]);
    auto z1 = z[1], z2 = z[2];
    z.pop_back(); z.pop_back();
    z.push_back(o[0]);
    o.pop_back();
    o.push_back(z1); o.push_back(z2);
    process2(z, o, ans);
}
 
void process4(vector<pair<int, int>> &z, vector<pair<int, int>> &o, vector<pair<int, int>> &ans){
 
    ans.push_back(o[3]);
    change(o[3]);
    z.push_back(o[3]);
    ans.push_back(o[1]);
    change(o[1]);
    z.push_back(o[1]);
    ans.push_back(o[2]);
    change(o[2]);
    z.push_back(o[2]);
    o.pop_back(); o.pop_back(); o.pop_back();
 
    process1(z, o, ans);
}
 
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> ma[i];
        vector<pair<int, int>> ans;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < m - 1; j++){
                vector<pair<int, int>> z, o;
                for(int k = 0; k < 4; k ++){
                    int ni = i + ii[k], nj = j + ji[k];
                    if(ma[ni][nj] == '0') z.push_back({ni + 1, nj + 1});
                    else o.push_back({ni + 1, nj + 1});
                }
                if(o.size() == 4) process4(z, o, ans);
                else if(o.size() == 3) process3(z, o, ans);
                else if(o.size() == 2) process2(z, o, ans);
                else if(o.size() == 1) process1(z, o, ans);
            }
        }
        if(ans.size() == 0) cout << 0 << endl;
        else{
            cout << ans.size() / 3 << endl;
            for(auto & p: ans) cout << p.first << " " << p.second << " ";
            cout << endl;
        }
    }
    return 0;
}