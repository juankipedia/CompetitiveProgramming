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

int k, n;
string s, t;


int main() {
    io_boost;
    cin >> k;
    while(k --){
        cin >> n;
        cin >> s >> t;
        vector<pair<int, int>> rv;
        bool f = true;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                bool fi = false;
                for(int j = i + 1; j < n; j++){
                    if(s[i] == s[j]){
                        swap(t[i], s[j]);
                        rv.push_back({j, i});
                        fi = true;
                        break;
                    }
                    if(s[i] == t[j]){
                        rv.push_back({j, j});
                        rv.push_back({j, i});
                        swap(s[j], t[j]);
                        swap(s[j], t[i]);
                        fi = true;
                        break;
                    }
                }
                if(not fi){
                    f = false;
                    break;
                }
            }
        }

        if(f){
            cout << "Yes" << endl;
            cout << rv.size() << endl;
            for(const auto &p: rv) cout << p.first + 1 << " " << p.second + 1 << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}