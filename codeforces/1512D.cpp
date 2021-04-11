# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli t, n, b[300005], s[300005];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        n += 2;
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        
        sort(b, b + n);
        s[0] = b[0];
        for(int i = 1; i < n; i++){
            s[i] = b[i] + s[i - 1];
        }
        lli sum = s[n - 2];
        int pos = -1;
        for(int i = 0; i < n - 1; i++){
            if(sum - b[i] == b[n - 1]){
                pos = i;
                break;
            }
        }
        if(pos != -1){
            for(int i = 0; i < n - 1; i++)
                if(i != pos) cout << b[i] << " ";
            cout << endl;
        }
        else{
            sum = s[n - 3];
            if(sum == b[n - 2]){
                for(int i = 0; i < n - 2; i++) cout << b[i] << " ";
                cout << endl;
            }
            else cout << -1 << endl;
        }
    }
    return 0;
}