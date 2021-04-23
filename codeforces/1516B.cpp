# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli arr[2005];

int main(){
    io_boost;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        lli acc = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            acc = acc ^ arr[i];
        }
        if(!acc){
            cout << "YES" << endl;
            continue;
        }
        bool flag = true;
        lli c = 0, cur;
        for(int i = 0; i < n; i++){
            if(arr[i] == acc && cur){
                flag = false;
                break;
            }
            else if(arr[i] == acc) c++;
            else{
                cur = cur ^ arr[i];
                if(cur == acc){
                    cur = 0;
                    c++;
                }
            }
        }
        if(flag && c >= 2){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    } 
    return 0;
}