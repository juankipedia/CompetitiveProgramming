#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, x;
string nines[] = {"9", "18", "27", "36", "45"};

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> x;
        int p = x / 9;
        if(x > 45) cout << -1 << endl;
        else if(p == 0) cout << x << endl;
        else{
            int r = 45 - x;
            int i = 0, j = 1;
            for(; i < 9; i++, j++){
                if(j > r){
                    cout << j - r;
                    j++;
                    i++;
                    break;
                }
                r -= j;
            }

            for(; i < 9; i++, j++) cout << j;
            cout << endl;

        }        
    }
    return 0;
}