#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

ulli N;
string a[65];
ulli ans[65];
int main(){
    cin >> N;
    for(ulli i = 1; i <= N; i++) cin >> a[i];
    ans[0] = 1;
    for(ulli i = 1; i <= N; i++){
        if(a[i] == "AND") ans[i] = ans[i - 1];
        else{
            ans[i] = (ans[i - 1] + (1ULL << i));
        }
    }
    cout << ans[N] << endl;
    return 0;
}