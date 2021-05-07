
# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t;
 
int main(){
    cin >> t;
    lli A, B;
    while(t--){
        cin >> A >> B;
        if(A * B == A){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << A << " " << A * (7 * B - 1)  << " " << A * B * 7 << endl;
    }
    return 0;
}