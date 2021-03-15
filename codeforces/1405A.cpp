# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> p;
        for(int i = 0, ai; i < n; i++) cin >> ai, p.push_back(ai);
        for(int i = n - 1; i >= 0; i--) cout << p[i] << " ";
        cout << endl;
    }
    return 0;
}