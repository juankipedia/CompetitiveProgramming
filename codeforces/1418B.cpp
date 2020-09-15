#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, l[100];
lli a[100], p[101];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<lli> u;
        for(int i = 0; i < n; i++){
            cin >> l[i];
            if(l[i] == 0) u.push_back(a[i]);
        }
        sort(u.begin(), u.end());
        int k1 = 0, k2 = 0;
        p[0] = 0;
        for(int i = 0, j = 0; i < n; i++){
            if(l[i] == 0){
                p[i + 1] = p[i] + u[j];    
                j++;
            }
            else p[i + 1] = p[i] + a[i];
            if(p[i] < 0) k1 = i;
        }
        reverse(u.begin(), u.end());
        p[0] = 0;
        for(int i = 0, j = 0; i < n; i++){
            if(l[i] == 0){
                p[i + 1] = p[i] + u[j];    
                j++;
            }
            else p[i + 1] = p[i] + a[i];
            if(p[i] < 0) k2 = i;
        }

        if(k1 < k2) reverse(u.begin(), u.end());

        for(int i = 0, j = 0; i < n; i++){
            if(l[i] == 0){
                cout << u[j] << " ";
                j++;    
            }
            else cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}