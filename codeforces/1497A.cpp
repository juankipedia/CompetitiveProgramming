# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[100], b[105], c[100];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        multiset<int> r;
        set<int> s;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(s.count(a[i])) r.insert(a[i]);
            else s.insert(a[i]);
        }
        for(int e: s) cout << e << " ";
        for(int e: r) cout << e << " ";
        cout << endl;
    }
    return 0;
}