#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, ans[10001];
int res = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) ans[i] = -1;
    int i = 0, j = 1, ans1, ans2;
    while(i < n && j < n){
        cout << "? " << i + 1 << " " << j + 1 << endl; cout.flush();
        cin >> ans1;
        cout << "? " << j + 1 << " " << i + 1 << endl; cout.flush();
        cin >> ans2;
        if(ans1 < ans2){
            ans[j] = ans2;
            j++;
        }
        else{
            ans[i] = ans1;
            i = j;
            j++;
        }
    }
    cout << "! ";
    for(int i = 0; i < n; i++)
        if(ans[i] == -1) cout << n << " ";
        else cout << ans[i] << " ";
    cout << endl;
    return 0;
}