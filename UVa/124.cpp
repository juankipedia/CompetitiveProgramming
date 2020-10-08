#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

map<char, set<char>> g;
string variables, conditions;
set<char> v;
map<char, int> ind;

void print_all(vector<char> &ans){
    bool all = true;
    for(auto &p: g){
        char V = p.first;
        if(v.find(V) == v.end() && ind[V] == 0){
            v.insert(V);
            for(char U: g[V]) ind[U]--;
            ans.push_back(V);
            print_all(ans);
            v.erase(V);
            for(char U: g[V]) ind[U]++;
            ans.erase(ans.end() - 1);
            all = false;
        }
    }
    if(all){
        for(char var: ans) cout << var;
        cout << endl;
    }
}

int main(){
    io_boost;
    bool f = true;
    while(getline(cin, variables, '\n')){
        getline(cin, conditions, '\n');
        if(!f){
            cout << endl;
        }
        else f = false;
        g.clear(); v.clear(); ind.clear();
        for(char c : variables)
            if(c != ' ') g[c] = set<char>();
        for(int i = 0; i < conditions.size(); i += 4)
            g[conditions[i]].insert(conditions[i + 2]);
        for(auto &p: g)
            for(char c: p.second) ++ind[c];
        vector<char> ans;
        print_all(ans);
    }
    
    return 0;
}