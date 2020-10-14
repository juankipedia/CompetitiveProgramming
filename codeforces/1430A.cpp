#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N;


int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> N;
        bool ok = false;
        int I, J, K;
        for(int i = 0; i < N; i++){
            if(7 * i > N) break; 
            for(int j = 0; j < N; j++){
                if((7 * i + 5 * j) > N) break;
                for(int k = 0; k < N; k++){
                    if((7 * i + 5 * j  + 3 * k) > N) break;
                    else if((7 * i + 5 * j  + 3 * k) == N){ 
                        I = i; J = j; K = k;
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            if(ok) break;
        }
        if(ok) cout << K << " " << J << " " << I << endl;
        else cout << -1 << endl;
    }
    return 0;
}