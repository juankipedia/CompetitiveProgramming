# include <bits/stdc++.h>
using namespace std;

# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(){
    io_boost;
    int t, n, a[105];
    cin >> t;
    while(t--){
        cin >> n;
        map<int, int> m;
        for(int i = 0; i < n; i++) cin >> a[i], m[a[i]]++;
        cout << (n - m.begin()->second) << endl;
    }
    return 0;
}