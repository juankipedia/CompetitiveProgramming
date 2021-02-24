#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, p[100000];


int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> p[i];
        int w = n;
        vector<int> ans;
        bool wb[n + 1] = {false}; 
        for(int i = n - 1; i >=0; ){
            stack<int> s;
            while(i >= 0 && p[i] != w){
                s.push(p[i]);
                wb[p[i]] = true;
                i--;
            }
            s.push(p[i]);
            wb[p[i]] = true;
            i--;
            while(!s.empty()) ans.push_back(s.top()), s.pop();
            int j = w;
            while(j > 0 && wb[j]) j--;
            w = j;
        }
        for(int e: ans) cout << e << " ";
        cout << endl;
    }
    return 0;
}