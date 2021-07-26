# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
 
int main(){
    io_boost;
    int t, n, letter;
    cin >> t;
    while(t--){
        cin >> n;
        string s;
        vector<string> w;
        for(int i = 0; i < n; i++){
            cin >> s;
            int c = 0;
            for(char &cc: s){
                c = cc - 'a';
                if(c > 4) break;
            }
            if(c <= 4) w.push_back(s);
        }
        vector<pair<int, vector<int>>> v;
        for(string &wd: w){
            v.push_back({wd.size(), vector<int>(5, 0)});
            for(char c: wd) v.rbegin()->second[c - 'a']++;
        }
        int res = 0;
        for(letter = 0; letter < 5; letter++){
            int ti = 0, nti = 0;
            vector<pair<int, pair<int, int>>> vv;
            for(auto &e: v){
                int a = e.second[letter], b = e.first - e.second[letter];
                ti += a, nti += b;
                vv.push_back({a - b, {a, b}});
            }
            sort(vv.begin(), vv.end());
            int ans  = vv.size(), p = 0;
            while(p < vv.size() && ti <= nti){
                ti -= vv[p].second.first;
                nti -= vv[p].second.second;
                p++;
                ans--;
            }
            res = max(res, ans);
        }
        cout << res << endl;
    }
    return 0;
}