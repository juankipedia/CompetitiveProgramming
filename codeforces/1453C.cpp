#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string b[2000];
lli area(int d){
    lli a = 0;
    set<lli> found;
    set<pair<lli, lli>> one;
    for(lli i = 0; i < n; i++){
        lli f = -1, s = -1;
        for(lli j = 0; j < n; j++){
            if(b[i][j] - '0' == d && f == -1) f = j;
            else if(b[i][j] - '0' == d) s = j;
        }
        if(f != -1) found.insert(i);
        if(f != -1 && s != -1){
            a = max({(s - f) * (n - 1 - i), (s - f) * (i - 0) , a});
            one.insert({i, f});
            one.insert({i, s});
        }
        else if(f != -1)
            one.insert({i, f});
    }
    if(found.size()){
        for(auto &p : one){
            a = max({(p.second - 0) * (p.first - *found.begin()), (n - 1 - p.second) * (p.first - *found.begin()),
            (p.second - 0) * (*found.rbegin() - p.first), (n - 1 - p.second) * (*found.rbegin() - p.first), a});
        }
    }
    found.clear();
    one.clear();

    for(lli i = 0; i < n; i++){
        lli f = -1, s = -1;
        for(lli j = 0; j < n; j++){
            if(b[j][i] - '0' == d && f == -1) f = j;
            else if(b[j][i] - '0' == d) s = j;
        }
        if(f != -1) found.insert(i);
        if(f != -1 && s != -1){
            a = max({(s - f) * (n - 1 - i), (s - f) * (i - 0) , a});
            one.insert({f, i});
            one.insert({s, i});
        }
        else if(f != -1)
            one.insert({f, i});
    }
    
    if(found.size()){
        for(auto &p : one){
            a = max({(p.first - 0) * (p.second - *found.begin()), (n - 1 - p.first) * (p.second - *found.begin()),
            (p.first - 0) * (*found.rbegin() - p.second), (n - 1 - p.first) * (*found.rbegin() - p.second), a});
        }
    }
    return a;
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> b[i];
        for(int i = 0; i <= 9; i++) cout << area(i) << " ";
        cout << endl;
    }   
    return 0;
}