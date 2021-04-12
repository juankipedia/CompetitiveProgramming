# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int  t, n, r[55];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int c[2] = {0};
        for(int i = 0; i < n; i++) cin >> r[i];
        for(int i = 0; i < n; i++){
            if(r[i] == 1) c[0]++;
            else if(r[i] == 2) c[1]++;
            else c[0]++;
        }
        cout << c[0] << endl;
    }
    return 0;
}