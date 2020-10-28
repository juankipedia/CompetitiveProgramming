#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli oo = numeric_limits<lli>::max();
int n;
lli l[300001], r[300001], pl[300001], pr[300001], sl[300001], sr[300001];


int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    pl[0] = 0;
    sl[n] = 0; 
    pr[0] = oo;
    sr[n] = oo;
	
	for(int i = 0; i < n; i++){
		pl[i + 1] = max(pl[i], l[i]);
		pr[i + 1] = min(pr[i], r[i]);
	}
	
	for (int i = n - 1; i >= 0; i--){
		sl[i] = max(sl[i + 1], l[i]);
		sr[i] = min(sr[i + 1], r[i]);
	}
	
	lli ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans, min(pr[i], sr[i + 1]) - max(pl[i], sl[i + 1]));
    cout << ans << endl;
    return 0;
}