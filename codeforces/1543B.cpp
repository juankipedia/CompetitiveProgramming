# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        lli sum = 0, ai;
        for(int i = 0; i < n; i++) cin >> ai, sum += ai;
        lli b = sum / n;
        lli N = (sum - b * n);
        cout << N * (n - N) << endl;
    }
    return 0;
}