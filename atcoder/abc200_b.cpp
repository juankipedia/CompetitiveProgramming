# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

ulli N, K;

int main(){
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        if(N % 200) N = stoull(to_string(N) + "200");
        else N /= 200;
    }
    cout << N << endl;
    return 0;
}