# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int a[100005], n;

int main(){
    io_boost;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] != 0) a[i] = 1;
        }
        if(a[n - 1] == 0){
            for(int i = 0; i < n; i++) cout << i + 1 << " ";
            cout << n + 1 << endl;
        }
        else if(a[0] == 1){
            cout << n + 1 << " ";
            for(int i = 0; i < n; i++) cout << i + 1 << " ";
            cout << endl;
        }
        else{
            vector<int> ans;
            for(int i = 0; i < n - 1; i++){
                ans.push_back(i + 1);
                if(a[i] == 0 && a[i + 1] == 1){
                    ans.push_back(n + 1);
                    for(int j = i + 1; j < n; j++) ans.push_back(j+ 1);
                    break;
                }
            }
            if(ans.size() != n + 1) cout << -1 << endl;
            else{
                for(int e : ans) cout << e << " ";
                cout << endl;
            }
        }
    }

    return 0;
}