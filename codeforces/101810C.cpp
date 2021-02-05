#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
ulli n;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        int pos;
        for(int i = 63; i >= 0; i--){
            if((1ULL << i) & n)
                pos = i;
        }
        cout << pos + 1 << endl;
    }
    return 0;
}