#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n, a[100];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int sum = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            if(a[i] == 1) cnt ++;
        }
        if(sum % 2 || (sum / 2) % 2 && cnt == 0){
            cout << "NO" << endl;
            continue;
        }
        else cout << "YES" << endl;
    }
    return 0;
}