# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[200];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        map<int, int> m;
        for(int i = 0; i < n; i++)
            m[a[i]]++;
        for(int i = 0; i < n; i++)
            if(m[a[i]] == 1){
                cout << i + 1 << endl;
                break;
            }
    }
    return 0;
}