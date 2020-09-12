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
        map<int, int> m;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            ++m[a[i]];
        }
        vector<bool> A(102), B(102);
        for(const auto &p: m){
            if(p.second > 1){
                A[p.first] = true;
                B[p.first] = true;
            }
            else
                A[p.first] = true;
            
        }
        int ma, mb;
        for(int i = 0; i <= 101; i++){
            if(!A[i]){
                ma = i;
                break;
            }
        }

        for(int i = 0; i <= 101; i++){
            if(!B[i]){
                mb = i;
                break;
            }
        }

        cout << ma + mb << endl;
    }
    return 0;
}