# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
string si;

vector<pair<string, int>> v[105];

bool is_prefix(string &s1, string &s2){
    for(int i = 0; i < s1.size(); i++)
        if(s1[i] != s2[i]) return false;
    return true;
}

bool is_sufix(string &s1, string &s2){
    for(int i = s1.size() - 1, j = s2.size() - 1; i >= 0; i--, j--)
        if(s1[i] != s2[j]) return false;
    return true;
}

int main(){
    cin >> n;
    for(int i = 0; i < 2 * n - 2; i++) cin >> si, v[si.size()].push_back({si, i});

    if(n == 2){
        cout << "PS" << endl;
        return 0;
    }

    int ans[2 * n - 1];
    string pre, su;
    if(is_prefix(v[1][0].first, v[2][0].first) && is_sufix(v[1][1].first, v[2][1].first)){
        ans[v[1][0].second] = 0;
        ans[v[2][0].second] = 0;
        pre = v[2][0].first;
        su = v[2][1].first;
        ans[v[1][1].second] = 1;
        ans[v[2][1].second] = 1;
    }
    else if(is_prefix(v[1][0].first, v[2][1].first) && is_sufix(v[1][1].first, v[2][0].first)){
        ans[v[1][0].second] = 0;
        ans[v[2][1].second] = 0;
        pre = v[2][1].first;
        su = v[2][0].first;
        ans[v[1][1].second] = 1;
        ans[v[2][0].second] = 1;
    }
    else if(is_sufix(v[1][0].first, v[2][0].first) && is_prefix(v[1][1].first, v[2][1].first)){
        ans[v[1][0].second] = 1;
        ans[v[2][0].second] = 1;
        pre = v[2][1].first;
        su = v[2][0].first;
        ans[v[1][1].second] = 0;
        ans[v[2][1].second] = 0;
    }
    else{
        ans[v[1][0].second] = 1;
        ans[v[2][1].second] = 1;
        pre = v[2][0].first;
        su = v[2][1].first;
        ans[v[1][1].second] = 0;
        ans[v[2][0].second] = 0;
    }
    
    for(int i = 2; i < n; i++){
        if(is_prefix(pre, v[i][0].first) && is_sufix(su, v[i][1].first)){
            pre = v[i][0].first;
            ans[v[i][0].second] = 0;

            su = v[i][1].first;
            ans[v[i][1].second] = 1;
        }
        else{
            pre = v[i][1].first;
            ans[v[i][1].second] = 0;

            su = v[i][0].first;
            ans[v[i][0].second] = 1;
        }
    }

    for(int i = 0; i < 2 * n - 2; i++)
        if(ans[i] == 0) cout << "P";
        else cout << "S";
    cout << endl;
    
    return 0;
}
