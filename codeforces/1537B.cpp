# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli t, n, m, i, j;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m >> i >> j;
        vector<lli> R = {1, n, 1, n}, C = {1, 1, m, m};
        lli rk, rl, maxi = -1;
        for(lli k = 0; k < 4; k++){
            for(lli l = 0; l < 4; l++){
                if((abs(R[k] - i) + abs(C[k] - j) + 
                    abs(R[k] - R[l]) + abs(C[k] - C[l]) + 
                    abs(R[l] - i) + abs(C[l] - j)) > maxi){
                    rk = k, rl = l;
                    maxi = abs(R[k] - i) + abs(C[k] - j) + 
                    abs(R[k] - R[l]) + abs(C[k] - C[l]) + 
                    abs(R[l] - i) + abs(C[l] - j);  
                }
            }
        }
        cout << R[rk] << " " << C[rk] << " " << R[rl] << " " << C[rl] << endl;
    }
    
    return 0;
}