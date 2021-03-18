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
        n -= k - 3;
        if(n % 2) cout << n / 2 << " " << n / 2 << " " << n - (n / 2) * 2 << " "; 
        else{
            if((n / 2) % 2) cout << (n / 2) - 1 << " " << (n / 2)  - 1<< " " << 2 << " ";
            else cout << (n / 2) / 2 << " " << (n / 2) / 2 << " " << (n / 2) << " ";
        }
        for(int i = 0; i < k - 3; i++) cout << 1 << " ";
        cout << endl;
    }
    return 0;
}