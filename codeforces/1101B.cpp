#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
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

int main() {
	io_boost
	string s;
	int l, l_c, r_c, count = 4,MAX = std::numeric_limits<int>::max();;
	pair<int, int> r;
	l = l_c = r_c = r.first =  r.second = MAX;
	cin >> s;

	for (int i = 0; i < s.length(); ++i){
		if(s[i] == '[' and l == MAX) l = i;
		else if (s[i] == ':' and l != MAX and l_c == MAX) l_c = i;
		else if(s[i] == ':' and l_c != MAX) r_c = i;
		else if(s[i] == ']' and l != MAX and r_c != MAX and l_c != MAX) r = make_pair(i, r_c);
	}
	if(l != MAX and l_c != MAX and r_c != MAX and r.first != MAX){
		for (int i = 0; i < s.length(); ++i)
			if(s[i] == '|' and i > l_c and i < r.second) count ++;
		cout << count << endl;
	}
	else
		cout << -1 << endl;
    return 0;
}