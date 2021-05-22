# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[51];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        bool sorted = true;
        for(int i = 1; i < n; i++) if(a[i] < a[i - 1]) sorted = false;
        if(sorted) cout << 0 << endl;
        else if(a[0] == 1 || a[n - 1] == n) cout << 1 << endl;
        else{
            if(a[0] == n && a[n - 1] == 1) cout << 3 << endl;
            else cout << 2 << endl;
        }

    }
    return 0;
}