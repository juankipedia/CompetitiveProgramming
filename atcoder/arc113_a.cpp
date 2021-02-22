#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int K;

int main(){
    cin >> K;
    int ans = 0;
    for(int A = 1; A <= K; A++){
        for(int B = 1; A * B <= K; B++){
            for(int C = 1; A * B * C <= K; C++){
                ans++;
            }
        }
    } 
    cout << ans << endl;
    return 0;
}