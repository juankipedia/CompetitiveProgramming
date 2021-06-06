# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

vector<string> ps;

string s, w;

void build(int i){
    if(i == 3) return;
    for(int j = 0; j < 26; j++){
        w += j + 'a';
        ps.push_back(w);
        build(i + 1);
        w.pop_back();
    }
}

int t, n;

int main(){
    io_boost;
    build(0);
    cin >> t;
    while(t--){
        cin >> n >> s;
        bool f = false;
        string ans;
        set<string> as;
        for(int i = 1; i <= 3; i++){
            for(int j = 0; j + i - 1 < n; j++) as.insert(s.substr(j, i));
            for(const string &j: ps){
                if(j.size() == i && !as.count(j)){
                    f = true;
                    ans = j;
                    break;
                }
            }
            if(f) break;
        }
        cout << ans << endl;
    }
    return 0;
}