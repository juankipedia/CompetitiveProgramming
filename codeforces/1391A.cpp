#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n;
 
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> l, h;
        for(int i = 1; i <= (n / 2); i++) l.push_back(i);
        for(int i = (n / 2) + 1; i <= n; i++) h.push_back(i);
        int j = 0, k = 0;
        for(int i = 0; i < n; i++){
            if(i % 2){
                cout << l[j] << " ";
                j++;
            }
            else{
                cout << h[k] << " ";
                k++;
            }
        }
        cout << endl;
 
    }
    return 0;
}