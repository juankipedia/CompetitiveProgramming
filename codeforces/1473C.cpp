# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        int offset = 2 * k - 1 - n;
        for(int i = 1; i <= offset; i++) cout << i << " ";
        for(int i = k; i >= offset + 1; i--) cout << i << " ";
        cout << endl;
    }
    return 0;
}