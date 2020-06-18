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

int t, n, p[100000], d[100000];

int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i ++) cin >> p[i];
        for(int i = 1; i < n; i ++)
            d[i] = p[i] - p[i - 1];
        if(d[1] > 0) d[0] = -20000;
        else d[0] = 20000;
        vector<int> ans;
        bool positive = d[0] > 0;
        for(int i = 1; i < n; i++){
            if(positive && d[i] > 0) continue;
            else if(positive && d[i] < 0){
                ans.push_back(p[i - 1]);
                positive = false;
            }
            else if(!positive && d[i] < 0) continue;
            else{
                 ans.push_back(p[i - 1]);
                positive = true;
            }
        }
        ans.push_back(p[n - 1]);
        cout << ans.size() << endl;
        for(const int &e: ans) cout << e << " ";
        cout << endl;
    }
    return 0;
}