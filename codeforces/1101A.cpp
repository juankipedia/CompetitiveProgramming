#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> v_i;
typedef vector<long long int> v_lli;
typedef vector<unsigned int> v_ui;
typedef vector<unsigned long long int> v_ulli;
typedef set<int> s_i;
typedef set<long long int> s_lli;
typedef set<unsigned int> s_ui;
typedef set<unsigned long long int> s_ulli;
typedef unordered_set<int> u_s_i;
typedef unordered_set<long long int> u_s_lli;
typedef unordered_set<unsigned int> u_s_ui;
typedef unordered_set<unsigned long long int> u_s_ulli;
void io_boost(){
    std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
}
# define endl "\n"
int main() {
	io_boost();
	ui t, l, r, d;
	cin >> t;
	while(t--){
		cin >> l >> r >> d;
		if(d < l or d > r)
			cout << d << endl;
		else
			cout << d * (r / d + 1) << endl;
	}
    return 0;
}