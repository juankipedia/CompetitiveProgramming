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

int main() {
	io_boost;
	int n, k , k_i;
	string s, s_i = "";
	cin >> n >> k >> s;
	char c = s[0];
	s_i += c;
	int i = 1;

	unordered_map<string, int> m;
	if(s_i.length() == k){
		++m[s_i];
		s_i = "";
		if(s.length() > 1){
			i = 2;
			c = s[1];
			s_i += c;
		}
		else{
			cout << 1 << endl;
			return 0;
		}
	}
	for (; i < n; ++i){
		if(s_i.length() == k){
			++m[s_i];		
			s_i = "";
			c = s[i];
			s_i += c;
			if(i + 1 == n){
				++m[s_i];
			}
		}
		else if(s[i] == c and s_i.length() < k){
			s_i += s[i];
			if(s_i.length() == k and i + 1 == n){
				++m[s_i];
			}
		}
		else if(s[i] != c){
			s_i = "";
			c = s[i];
			s_i += c;
		}
	}
	int r = 0;
	for(const auto &e: m)
		if(e.second > r)
			r = e.second;
	cout << r << endl;
    return 0;
}