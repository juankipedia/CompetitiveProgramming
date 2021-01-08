#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
 
 
int main(){
    io_boost;
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        if(N == 1){ cout << 9 << "\n";}
        else if(N == 2){cout << 98 << "\n";}
        else if(N == 3){
            cout << 989 << "\n";
        }
        else{
            cout << 989;
            for(int i = 0; i < N - 3; i++) cout << i % 10;
            cout << "\n";
        }
    }
    
    return 0;
}