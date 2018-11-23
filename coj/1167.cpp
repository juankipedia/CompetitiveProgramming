#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int c;
	cin >> c;
	while(c--){
		int n;
		cin >> n;
		vector<string> w(n);
		vector<int> s(n);

		for(int i = 0; i < n; ++i)
			cin >> w[i], s[i] = w[i].length();

		vector<int> graph(n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
			{
				if(j == i)
					continue;
				if(w[i][0] == w[j][s[j] -  1])
					graph[i] |= (1 << j);
			}

		int ans = 0;
		vector<int> dp((1 << n));

		for(int i = 1, temp = 0; i < (1 << n); ++i, temp = 0)
		{
			if(i == (i & (-i)))
				dp[i] = i;
			for(int j = 0; j < n; ++j)
			{
				if(!((1 << j) & i))
					continue;
				dp[i] |= (dp[i ^ (1 << j)] & graph[j]) ? (1 << j) : 0;
				temp += s[j];
			}
			ans = max(ans, (dp[i]) ? temp : 0);
		}

		cout << ans << endl;
	}

	return 0;
}