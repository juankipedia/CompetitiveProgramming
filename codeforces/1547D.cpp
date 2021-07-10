# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

ulli get(ulli c, ulli acc){
    ulli ans = 0;
    for(ulli i = 0; i < 64; i++){
        ulli w = (1 << i);
        if(!(c & w) && (acc & w)) ans |= w;
    }
    return ans;
}

int t, n;
ulli x[200005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> x[i];
        cout << 0 << " ";
        ulli acc = x[0];
        for(int i = 1; i < n; i++){
            ulli y = get(x[i], acc);
            acc = x[i] ^ y;
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}