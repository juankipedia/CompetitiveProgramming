#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[100];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        set<int> s; vector<int> r;
        for(int i = 0; i < 2 * n; i ++){
            cin >> a[i];
            if(s.find(a[i]) == s.end()){
                s.insert(a[i]);
                r.push_back(a[i]);
            }
        }
        for(const int &ri: r) cout << ri << " ";
        cout << endl;
    }
    return 0;
}