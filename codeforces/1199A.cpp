# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, x, y, a[100000];

int main(){
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        bool ok = true;
        for(int j = i - 1; j >= i - x && j >= 0; j--)
            if(a[i] >= a[j]) ok = false;
        for(int j = i + 1; j <= i + y && j < n; j++)
            if(a[i] >= a[j]) ok = false;
        if(ok){
            cout << i + 1 << endl;
            return 0;
        }
    }
    
    return 0;
}