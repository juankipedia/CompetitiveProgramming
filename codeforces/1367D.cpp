#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int q, m, b[50];
string s, t;

int main(){
    io_boost;
    cin >> q;
    while(q--){
        cin >> s >> m;
        for(int i = 0; i < m; i++) cin >> b[i];
        t = string(m, '+');
        vector<vector<int>> g;
        while(true){
            vector<int> pos;
            for(int i = 0; i < m; i++)
                if(b[i] == 0) pos.push_back(i);
            if(pos.empty())
                break;
            for(int i = 0; i < m; i++)
                if(b[i] == 0) b[i] = -1;
                else 
                    for (int pp: pos)
                        b[i] -= abs(i - pp);
            g.push_back(pos);
        }
        map<char, int> memo;
        for(int i = 0; i < s.size(); i++) ++memo[s[i]];
        auto j = memo.rbegin();
        for(const vector<int> &pos: g){
            while(j->second < pos.size()) j++;
            for(const int &p: pos)
                t[p] = j->first;
            j++;            
        }
        cout << t << endl;
        
    }
    return 0;
}