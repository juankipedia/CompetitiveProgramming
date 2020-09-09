#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[1000], d[1000];

int main(){
    cin >> t;
    while (t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        if(n == 2){
            if(abs(a[0] - a[1]) != 0){
                cout << 1 << endl;
                cout << 0 << endl;
            }
            else{
                cout << n << endl;
                cout << a[0] << " " << a[1] << endl;
            }
        }
        else{
            for(int i = 0, j = 0; i < n; i+= 2, j++){
                d[j] = a[i] - a[i + 1];
                //cout << j << endl;
            }
            vector<int> ans;
            int r = n / 2;
            if(r % 2 != 0) r--;
            for(int i = 0; i < r; i+= 2){
                if(d[i] != 0 && d[i + 1] != 0){ 
                    ans.push_back(0);
                    ans.push_back(0);
                }
                else if(d[i] == 0 && d[i + 1] != 0){
                    ans.push_back(a[2 * i]);
                    ans.push_back(a[2 * i + 1]);
                }
                else if(d[i] != 0 && d[i + 1] == 0){
                    ans.push_back(a[2 * (i + 1)]);
                    ans.push_back(a[2 * (i + 1) + 1]);
                }
                else{
                    ans.push_back(a[2 * i]);
                    ans.push_back(a[2 * i + 1]);
                }
            }
            if((n / 2) % 2){
                if(d[r] != 0){ 
                    ans.push_back(0);
                }
                else{
                    ans.push_back(a[2 * r]);
                    ans.push_back(a[2 * r + 1]);
                }
            }
            cout << ans.size() << endl;
            for(int e: ans) cout << e << " ";
            cout << endl;
        }
    }
    
    return 0;
}