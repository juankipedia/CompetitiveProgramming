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

int t;
lli r, b, k, lcm, bb, rr, w;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	io_boost;
	cin >> t;
	while(t--){
		cin >> r >> b >> k;
		if(r > b) swap(r, b);
		lcm = r*b/gcd(r,b);
		rr = lcm/r - 1;
		bb = lcm/b;
		w = (rr + bb - 1) / bb; 
		if(w < k) cout << "OBEY" << endl;
		else cout << "REBEL" << endl;
	}
    return 0;
}