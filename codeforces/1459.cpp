#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        string R, B;
        cin >> n;
        cin >> R >> B;
        int r = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(R[i] > B[i]) r++;
            else if(B[i] > R[i]) b++;
        }
        if(r == b) cout << "EQUAL" << endl;
        else if(r > b) cout << "RED" << endl;
        else cout << "BLUE" << endl;
    }
    
    return 0;
}