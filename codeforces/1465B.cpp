#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;

long long int TT; ulli n; string SS;

int main(){
    io_boost;
    cin >> TT;
    while(TT--){
        cin >> n;
        while (true){
            SS = to_string(n);
            bool ff = true;
            for(int i = 0; i < SS.size(); i++){
                if(SS[i] != '0' && 
                n % (SS[i] - '0')){
                    ff = false; break;
                }
            }
            if(ff){
                break;
            }
            n++;
        }
        cout << n << endl;
    }
    return 0;
}