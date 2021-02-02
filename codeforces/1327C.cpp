#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, m, k;
vector<pair<int, int>> M, MM;
bool ok[200];
 
int main(){
    io_boost;
    cin >> n >> m >> k;
    for(int i = 0, x, y; i < k; i++) cin >> x >> y;
    for(int i = 0, x, y; i < k; i++) cin >> x >> y;
    string ans = string(n - 1, 'D') + string(m - 1, 'R');
    for(int i = 0;i < n; i++){
		if(i % 2 == 0) for(int i = 1;i < m; i++)ans += "L";
		else for(int i = 1;i < m; i++)ans += "R";
		if(i != n - 1) ans += "U";
	}
    cout << ans.size() << endl;
    cout << ans << endl;
 
    
    return 0;
}