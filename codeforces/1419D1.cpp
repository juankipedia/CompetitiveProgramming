#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
lli a[100000];

int main(){
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    if(n < 3){
        cout << 0 << endl;
        for(int i = 0; i < n; i ++) cout << a[i] << " ";
        cout << endl;
        return 0;
    }
    sort(a, a + n);

    vector<lli> v1, v2;
    for(int i = n / 2; i < n; i++) v1.push_back(a[i]);
    for(int i = 0; i < n / 2; i++) v2.push_back(a[i]);
    bool v1t = true;
    int i = 0, j = 0;
    vector<lli> ans;
    while (true){
        if(v1t && i < v1.size()){
            ans.push_back(v1[i]);
            i++;
        }
        else if(j < v2.size()){
            ans.push_back(v2[j]);
            j++;
        }
        v1t = !v1t;
        if(i >= v1.size() && j >= v2.size()) break;
    }
    int cnt = 0;
    for(int i = 1; i < n - 1; i++)
        if(ans[i] < ans[i + 1 ] && ans[i] < ans[i - 1]) cnt++;
    cout << cnt << endl;
    for(int i = 0; i < n; i ++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}