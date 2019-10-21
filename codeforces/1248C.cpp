#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

const ulli mod = 1000000007;
int n, m;
ulli memo[100000][2][2];
ulli memon[100000][2][2];

ulli fm(ulli i, ulli b, ulli c){
	if(i == m - 1) return 1;
	
	if(memo[i][b][c]) return memo[i][b][c];

	if(b == 1 and c){
		memo[i][b][c] = ((fm(i + 1, 0, 1) % mod) + (fm(i + 1, 1, 0) % mod)) % mod;
		return memo[i][b][c];
	}
	else if(b == 1 and not c){
		memo[i][b][c] = fm(i + 1, 0, 1) % mod;
		return memo[i][b][c];
	}
	else if(b == 0 and c){
		memo[i][b][c] = ((fm(i + 1, 1, 1) % mod) + (fm(i + 1, 0, 0) % mod)) % mod;
		return memo[i][b][c];
	}
	else{
		memo[i][b][c] = fm(i + 1, 1, 1) % mod;
		return memo[i][b][c];
	}
	
}

ulli fn(ulli i, ulli b, ulli c){
	if(i == n - 1) return 1;
	
	if(memon[i][b][c]) return memon[i][b][c];

	if(b == 1 and c){
		memon[i][b][c] = ((fn(i + 1, 0, 1) % mod) + (fn(i + 1, 1, 0) % mod)) % mod;
		return memon[i][b][c];
	}
	else if(b == 1 and not c){
		memon[i][b][c] = fn(i + 1, 0, 1) % mod;
		return memon[i][b][c];
	}
	else if(b == 0 and c){
		memon[i][b][c] = ((fn(i + 1, 1, 1) % mod) + (fn(i + 1, 0, 0) % mod)) % mod;
		return memon[i][b][c];
	}
	else{
		memon[i][b][c] = fn(i + 1, 1, 1) % mod;
		return memon[i][b][c];
	}
	
}


int main() {
	cin >> n >> m;
	cout << ((fm(0, 1, 1) * 2) + (fn(0, 1, 1) * 2) - 2)%mod << endl;
    return 0;
}