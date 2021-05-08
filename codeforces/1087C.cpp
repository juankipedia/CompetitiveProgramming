# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int x[3], y[3];

struct edge{
    int dis, id;
    vector<pair<int, int>> path, pathp;
};

pair<int, vector<pair<int, int>>> get(int xi, int yi, int b){
    vector<pair<int, int>> res;

    while(yi != y[b]){
        res.emplace_back(xi, yi);
        if(yi > y[b]) yi--;
        else if(yi < y[b]) yi++;
    }

    while(xi != x[b]){
        res.emplace_back(xi, yi);
        if(xi > x[b]) xi--;
        else if(xi < x[b]) xi++;
    }


    res.emplace_back(xi, yi);

    return {res.size(), res};
}


pair<int, vector<pair<int, int>>> get_alt(int xi, int yi, int b){
    vector<pair<int, int>> res;


    while(xi != x[b]){
        res.emplace_back(xi, yi);
        if(xi > x[b]) xi--;
        else if(xi < x[b]) xi++;
    }


    while(yi != y[b]){
        res.emplace_back(xi, yi);
        if(yi > y[b]) yi--;
        else if(yi < y[b]) yi++;
    }


    res.emplace_back(xi, yi);

    return {res.size(), res};
}

int main(){
    for(int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    vector<edge> ans;

    auto aux = get(x[0], y[0], 1), aux_alt = get_alt(x[0], y[0], 1);
    ans.push_back({aux.first, 0, aux.second, aux_alt.second});
    aux = get(x[0], y[0], 2); aux_alt = get_alt(x[0], y[0], 2);
    ans.push_back({aux.first, 1, aux.second, aux_alt.second});
    aux = get(x[1], y[1], 2); aux_alt = get_alt(x[1], y[1], 2);
    ans.push_back({aux.first, 2, aux.second, aux_alt.second});
    
    sort(ans.begin(), ans.end(), [](auto &A, auto &B){
        return A.dis < B.dis;
    });

    int t;

    if(ans[0].id == 0) t = 2;
    else if(ans[0].id == 1) t = 1;
    else t = 0;

    pair<int, vector<pair<int, int>>> mini;
    mini.first = 1e9 + 7;
    bool pp = false;

    for(auto &p: ans[0].path){
        aux = get(p.first, p.second, t);
        if(aux.first < mini.first)
            mini = aux;
    }

    for(auto &p: ans[0].pathp){
        aux = get(p.first, p.second, t);
        if(aux.first < mini.first)
            mini = aux, pp = true;
    }

    set<pair<int, int>> res;
    if(!pp) for(auto e: ans[0].path) res.insert(e);
    else for(auto e: ans[0].pathp) res.insert(e);
    for(auto e: mini.second) res.insert(e);

    cout << res.size() << endl;
    for(auto e: res)
        cout << e.first << " " << e.second << endl;

    return 0;
}