# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, k; 
lli a[200005];
string s;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> s;
    multiset<lli, std::greater<lli>> ss;
    int i = 0;
    char c = s[0];
    lli ans = 0;
    while(i < n){
        while(i < n && s[i] == c) ss.insert(a[i]), i++;
        int j = 0;
        for(lli e: ss){
            if(j >= k) break;
            ans += e;
            j++;
        }
        if(i < n) c = s[i];
        ss.clear();
    }
    cout << ans << endl;
    return 0;
}