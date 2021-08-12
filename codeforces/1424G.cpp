# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int n, d[100005], b[100005];

int main(){
    io_boost;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> b[i] >> d[i];
    sort(b, b + n);
    sort(d, d + n);
    d[n] = 1e9 + 5;
    int cnt = 0, year, res = 0;
    for(int i = 0, j = 0; i < n; i++){
        cnt++;
        while(b[i] >= d[j]) cnt--, j++;
        if(cnt > res) res = cnt, year = b[i];
    }
    cout << year << " " << res << endl;
    return 0;
}