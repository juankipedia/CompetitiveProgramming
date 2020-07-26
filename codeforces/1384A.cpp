#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[100];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<string> ans;
        if(a[0] != 0){
            ans.push_back(string(a[0], 'a'));
            ans.push_back(string(a[0], 'a'));
        }
        else{
            ans.push_back("b");
            ans.push_back("a");
        }
        bool A = true;
        for(int i = 1; i < n; i++){
            if(a[i] == 0){
                char c = (ans.back()[0] == 'a') ? 'b' : 'a';
                A = (c == 'a') ? true : false;
                ans.push_back(string(1, c));
            }
            else if(a[i] >= ans.back().size()){
                char c = (A) ? 'b' : 'a';
                A = !A;
                ans.back() += string(a[i] - ans.back().size(), c);
                ans.push_back(ans.back());
            }
            else{
                if(ans.back()[a[i]] == 'a') A = true;
                else A = false;
                ans.push_back(ans.back().substr(0, a[i]));
            }
        }
        for(const auto &str: ans)
            cout << str << endl;
    }
    return 0;
}