# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int oo = 1e9;

int N, M, K;
vector<int> o, z;
lli dp[5005][5005];

int main(){
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for(int i = 0, ai; i < N; i++){
		cin >> ai;
		if(ai) o.push_back(i);
		else z.push_back(i);
	}
	M = o.size();
	K = z.size();
	
	for(int i = 0; i <= K; i++) dp[M][i] = 0;
	for(int i = 0; i < M; i++) dp[i][K] = oo;

	for(int i = M - 1; i >= 0; i--)
		for(int j = K - 1; j >= 0; j--)
			dp[i][j] = min(dp[i + 1][j + 1] + abs(o[i] - z[j]), dp[i][j + 1]);
	cout << dp[0][0] << endl;
	return 0;
}