#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, a[100];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> b;
    bool z = false, neg = false, po = true;
    for(int i = 0; i < n -1; i++){
        if((a[i + 1] - a[i]) > 0){
            if(z || neg){
                cout << "NO" << endl;
                return 0;
            }
        }
        if(((a[i + 1] - a[i]) < 0)){
            neg = true;
        }
        if(a[i + 1] == a[i]){
            if(neg){
                cout << "NO" << endl;
                return 0;
            }
            z = true;
        }

    }
    cout << "YES" << endl;
    return 0;
}