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
        if(n % 2){
            cout << "3 1 2 ";
            for(int i = 4; i < n; i += 2) cout << i + 1 << " " << i << " ";
            cout << endl;
        }
        else{
            for(int i = 1; i < n; i += 2) cout << i + 1 << " " << i << " ";
            cout << endl;
        }
    }
    return 0;
}