# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, k, X;

int main(){
	cin >> t;
	while(t--){
		cin >> k >> X;
		vector<int> d;
		for(int i = 10 - k; i <= 9; i++) d.push_back(i);
		int b = d.size();
		vector<int> ans;
		bool l = 0;
		while(X){
			int p = X % b;
			if(!p) p = b;
			ans.push_back(d[p - 1]);
			if(X == b) break;
			X /= b;
			if(p == b) X--;
		}
		for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
		cout << endl;
	}
    return 0;
}