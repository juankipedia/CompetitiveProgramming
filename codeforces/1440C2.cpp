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
void change(const pair<int, int> &p){
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
        int N = n, M = m;
        for(int i = 0; i < n; i++) cin >> ma[i];

        vector<pair<int, int>> ans;


        if(m % 2){
            for(int j = 0; j < n - 1; j++){
                if(ma[j][m - 1] == '0') continue;
                change({j + 1, m});
                change({j + 1, m - 1});
                change({j + 2, m - 1});
                ans.push_back({j + 1, m});
                ans.push_back({j + 1, m - 1});
                ans.push_back({j + 2, m - 1});
            }
            if(ma[n - 1][m - 1] == '1'){
                change({n, m});
                change({n, m - 1});
                change({n - 1, m - 1});
                ans.push_back({n, m});
                ans.push_back({n, m - 1});
                ans.push_back({n - 1, m - 1});
            }
        }


        if(n % 2){
            for(int j = 0; j < m - 2; j++){
                if(ma[n - 1][j] == '0') continue;
                change({n, j + 1});
                change({n - 1, j + 1});
                change({n - 1, j + 2});
                ans.push_back({n, j + 1});
                ans.push_back({n - 1, j + 1});
                ans.push_back({n - 1, j + 2});
            }

            if(ma[n - 1][m - 2] == '1' && m % 2){
                change({n, m - 1});
                change({n - 1, m - 1});
                change({n - 1, m - 2});
                ans.push_back({n, m - 1});
                ans.push_back({n - 1, m - 1});
                ans.push_back({n - 1, m - 2});
            }
            else if(ma[n - 1][m - 2] == '1'){
                change({n, m - 1});
                change({n - 1, m - 1});
                change({n - 1, m});
                ans.push_back({n, m - 1});
                ans.push_back({n - 1, m - 1});
                ans.push_back({n - 1, m});

            }

            if(m % 2 == 0){
                if(ma[n - 1][m - 1] == '1'){
                    change({n, m});
                    change({n - 1, m});
                    change({n - 1, m - 1});
                    ans.push_back({n, m});
                    ans.push_back({n - 1, m});
                    ans.push_back({n - 1, m - 1});
                }
            }
        }


        if(n % 2) n--;
        if(m % 2) m --;
        
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < m - 2; j++){
                if(ma[i][j] == '1'){
                    change({i + 1, j + 1});
                    change({i + 2, j + 1});
                    change({i + 2, j + 2});
                    ans.push_back({i + 1, j + 1});
                    ans.push_back({i + 2, j + 1});
                    ans.push_back({i + 2, j + 2});
                }
            }
        }



        for(int i = 0; i < n; i += 2){
            vector<pair<int, int>> z, o;
            for(int k = 0; k < 4; k ++){
                int ni = i + ii[k], nj = m - 2 + ji[k];
                if(ma[ni][nj] == '0') z.push_back({ni + 1, nj + 1});
                else o.push_back({ni + 1, nj + 1});
            }
            if(o.size() == 4) process4(z, o, ans);
            else if(o.size() == 3) process3(z, o, ans);
            else if(o.size() == 2) process2(z, o, ans);
            else if(o.size() == 1) process1(z, o, ans);
        }


        for(int i = 0; i < m - 2; i += 2){
            vector<pair<int, int>> z, o;
            for(int k = 0; k < 4; k ++){
                int ni = n - 2 + ii[k], nj = i + ji[k];
                if(ma[ni][nj] == '0') z.push_back({ni + 1, nj + 1});
                else o.push_back({ni + 1, nj + 1});
            }
            if(o.size() == 4) process4(z, o, ans);
            else if(o.size() == 3) process3(z, o, ans);
            else if(o.size() == 2) process2(z, o, ans);
            else if(o.size() == 1) process1(z, o, ans);
        }

        if(ans.size() == 0) cout << 0 << endl;
        else{
            cout << ans.size() / 3 << endl;
            int c = 0;
            for(auto & p: ans){
                //if(p.first == 0 || p.second == 0) cout << "----" << N <<"-"<< M << endl;
                cout << p.first << " " << p.second << " ";
                c++;
                if(c == 3) cout << endl, c = 0;
            }
        }
    }
    return 0;
}