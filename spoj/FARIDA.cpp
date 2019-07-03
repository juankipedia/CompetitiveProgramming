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

const int MAXN = 100000;
ulli c[MAXN];
int n, t;

ulli max_coin(int i, unordered_map<int, ulli> &mem){
	if(mem.find(i) != mem.end())
		return mem[i];
	if(i >= n)
		return 0;

	ulli maxi;

	maxi = max(c[i] + max_coin(i + 2,  mem), c[i] + max_coin(i + 3,  mem));
	
	mem[i] = maxi;
	return maxi;
}

ulli max_coin_(){
	unordered_map<int, ulli> mem;
	return max(max_coin(0, mem), max_coin(1, mem));
}

int main() {
	cin >> t;
	for (int j = 0; j < t; ++j){
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> c[i];
		cout << "Case "<< j + 1 << ": " << max_coin_()  << endl;
	}
    return 0;
}