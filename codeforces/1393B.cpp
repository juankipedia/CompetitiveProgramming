#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, ai, q, x, cnt[100001];
string s;
set<pair<int, int>> p;

bool check(){
    if(p.size() == 0)
        return false;

    auto it  = p.end(); it--;

    if(it->first >= 8)
        return true;
    
    if(p.size() == 1)
        return false;

    auto p_it = it; p_it--;
    auto l = *it; 
    auto ll = *p_it;
    if(l.first >= 6 && ll.first >= 2)
        return true;

    if(l.first >= 4 && ll.first >= 4)
        return true;

    if(p.size() < 3)
        return false;
    auto p_p_it = p_it; p_p_it--;
    auto lll = *p_p_it;
    if(l.first >= 4 && ll.first >= 2 && lll.first >= 2)
        return true;
    
    return false;
}

int main(){
    io_boost;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ai;
        cnt[ai]++;
    }

    for(int i = 0; i <= 100000; i++)
        if(cnt[i] != 0)
            p.insert({cnt[i], i});

    cin >> q;
    while(q--){
        cin >> s >> x;

        auto it = p.find({cnt[x], x});
        if(it != p.end())
            p.erase(it);
        if(s == "+"){
            cnt[x]++;
            p.insert({cnt[x], x});
        }
        else{
            cnt[x]--;
            if(cnt[x])
                p.insert({cnt[x], x});
        }
        //for(auto par : p)
            //cout << par.first << " " << par.second << endl;    
        if(check()) cout << "YES\n";
        else cout << "NO\n"; 
    }
    return 0;
}


