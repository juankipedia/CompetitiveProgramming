#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const int MAX = 1000000;
bool prime[MAX + 1];
 
void sieve_of_eratosthenes(int n){
    memset(prime, true, sizeof(prime));
    for(int p = 2; p * p <= n; p++){ 
        if(prime[p] == true){ 
            for(int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        }
    }
}
 
int t, d;
 
 
int main(){
    io_boost;
    sieve_of_eratosthenes(MAX);
    cin >> t;
    while(t--){
            cin >> d;
    lli ans = 1;
    for(lli i = 1 + d, j = 0; j < 2;){
        if(prime[i]){
            //cout << i << endl;
            ans *= i;
            i += d;
            j++;
        }
        else i++;
    }
    cout << ans << endl;        
    }
 
    return 0;
}