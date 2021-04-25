# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, k;


int main(){
    cin >> n >> k;
    if(k == 0) cout << -1 << endl;
    else{
        for(int i = 0; i < k - 1; i++) cout << i + 2 << " ";
        cout << 1 << " ";
        for(int i = k + 1; i <= n; i++) cout << i << " ";
        cout << endl; 
    }
    return 0;
}