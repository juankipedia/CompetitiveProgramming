# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
lli n, k;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n % 2) cout << n / 2 << " " << n / 2 << " " << n - (n / 2) * 2 << endl; 
        else{
            if((n / 2) % 2) cout << (n / 2) - 1 << " " << (n / 2)  - 1<< " " << 2 << endl;
            else cout << (n / 2) / 2 << " " << (n / 2) / 2 << " " << (n / 2) << endl;
        }
    }
    return 0;
}