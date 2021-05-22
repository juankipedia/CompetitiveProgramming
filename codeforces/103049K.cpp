# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string s, t;

int main(){
    getline(cin, s, '\n');
    getline(cin, t, '\n');
    map<char, int>  ms, mt;
    for(char c: s) ms[c]++;
    for(char c: t) mt[c]++;
    for(auto &p: ms)
        if(p.second * 2 == mt[p.first]){
            cout << p.first;
        }
    cout << endl;
    return 0;
}