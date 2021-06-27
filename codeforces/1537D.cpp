# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int biggest_factor(int n){
    int ans = 0;
    while(n % 2 == 0) ans = 2, n = n/2;  
    for(int i = 3; i * i <= n; i = i + 2)  
        while(n % i == 0) ans = i, n = n/i;
    if(n > 2) ans = max(n, ans);
    return ans;
}
 
int t, n;
 
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int f = biggest_factor(n);
        if(f == 2){
            if(int(log2(n)) % 2) cout << "Bob" << endl;
            else cout << "Alice" << endl;
        }
        else if(f == n || n == 1 || (n / f) % 2) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
    return 0;
}