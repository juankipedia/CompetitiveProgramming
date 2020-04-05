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


int t, s, e, n;

int main() {
    io_boost;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> n;
        vector<pair<int, pair<int, int>>> act;
        for(int i = 0; i < n; i++){
            cin >> s >> e;
            act.push_back({s,{e, i}});
        }
        sort(act.begin(), act.end());
        int c = 0, j = 0;
        int a[n] = {0};
        bool f = false;
        for(const auto &p: act){
            if(c <= p.first){
                c = p.second.first;
                a[p.second.second] = 1;
            }
            else if(j <= p.first){
                j = p.second.first;
                 a[p.second.second] = 2;
            }
            else{
                f = true;
                break;
            }
        }
        if(f) cout << "Case #" << ti << ": " << "IMPOSSIBLE" << endl;
        else{
            cout << "Case #" << ti << ": ";
            for(int i = 0; i < n; i++)
                if(a[i] == 1) cout << "C";
                else cout << "J";
            cout << endl;
        }
    }
    return 0;
}