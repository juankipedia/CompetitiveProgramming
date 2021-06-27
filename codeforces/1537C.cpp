# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, h[200005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> h[i];
        sort(h, h + n);
        int l, r, mini = numeric_limits<int>::max();
        for(int i = 0; i < n - 1; i++){
            if(h[i] == h[i + 1]){
                l = i;
                r = i + 1;
                break;
            }
            else if((h[i + 1] - h[i]) < mini){
                l = i;
                r = i + 1;
                mini = (h[i + 1] - h[i]);
            }
        }
        cout << h[l] << " ";
        for(int i = r + 1; i < n; i++) cout << h[i] << " ";
        for(int i = 0; i < l; i++) cout << h[i] << " ";
        cout << h[r] << endl;
    }
    
    return 0;
}