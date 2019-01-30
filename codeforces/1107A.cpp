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

bool is_imposible(string & s){
	if(s.length() == 2 and (s[0] >= s[1]))
		return true;
	return false;
}


int main() {
	
	int n, q;
	string s;
	cin >> q;
	while(q--){
		cin >> n >> s;
		if(is_imposible(s))
			cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << s[0] << " " << s.substr(1, s.length() - 1) << endl;
		}
	}
	return 0;
}