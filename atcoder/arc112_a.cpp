#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli L, R;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> L >> R;
        ulli MID = L *2ULL;
        if(MID > R) cout << 0 << endl;
        else{
            //cout << "MID " << MID << endl;
            ulli MAX = MID - L;
            ulli A = MAX - L + 1;
            ulli D = R - MID + 1;
            ulli ANS = D * (D - 1) / 2;
            //cout << MID << " " << A << " " << MAX << " " << D << " " << ANS << endl;
            cout << ANS + D * A << endl;
        }
    }
    return 0;
}