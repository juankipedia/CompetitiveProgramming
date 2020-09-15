#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, q, t;
lli pi;
set<lli> p;
map<lli, int> d;

void add(lli x){
    if(p.size()){
        lli r = -1, l = -1;
        auto rp = p.lower_bound(x);
        if(rp != p.end()) r = *rp;
        if(rp != p.begin()){
            rp--;
            l = *rp;
        }
        if(l != -1 && r != -1){ if(--d[r - l] == 0) d.erase(r - l); }
        if(l != -1) ++d[x - l];
        if(r != -1) ++d[r - x];
    }
    p.insert(x);
}

void remove(lli x){
    p.erase(x);
    if(p.size()){
        lli r = -1, l = -1;
        auto rp = p.lower_bound(x);
        if(rp != p.end()) r = *rp;
        if(rp != p.begin()){
            rp--;
            l = *rp;
        }
        if(l != -1 && r != -1) ++d[r - l];
        if(l != -1){ if(--d[x - l] == 0) d.erase(x - l); }
        if(r != -1){ if(--d[r - x] == 0) d.erase(r - x); }
    }
}

lli get(){
    if(p.size() < 3) return 0;
    return *p.rbegin() - *p.begin() - d.rbegin()->first; 
}

int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> pi;
        add(pi);
    }
    cout << get() << endl;
    while(q--){
        cin >> t >> pi;
        if(t == 1) add(pi);
        else remove(pi);
        cout << get() << endl;
    }
    return 0;
}