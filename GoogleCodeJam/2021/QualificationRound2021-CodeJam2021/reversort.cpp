# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[105];

int get_min(int i){
    int mini  = 10000, pos;
    for(int j = i; j < n; j++)
        if(a[j] < mini)
            mini = a[j],
            pos = j;
    return pos;
}

int main(){
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            int j = get_min(i);
            ans += j - i + 1;
            for(int l = j, k = i; k < l; l--, k++) swap(a[l], a[k]);
        }
        cout << "Case #" << ti << ": " << ans << endl; 
    }
    return 0;
}