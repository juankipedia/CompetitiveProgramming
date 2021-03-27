# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli ans = numeric_limits<lli>::max();
int n;
lli a[25];

void orxor(lli i, lli XOR){
    if(i >= n){
        ans = min(XOR, ans);
        return;
    }
    lli OR = a[i];
    for(int j = i; j < n; j++){
        OR = a[j] | OR;
        orxor(j + 1, XOR ^ OR);
    }
    return;
}

int main(){
    cin >> n;
    for(int  i = 0; i < n; i++) cin >> a[i];
    orxor(0, 0);
    cout << ans << endl;
    return 0;
}