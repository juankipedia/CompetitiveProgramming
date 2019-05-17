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

int n;
unordered_map<char, int> c1, c2;
unordered_map<char, bool> c;
string s;

int combination(int n, int k) { 
  if (k==0 || k==n) return 1; 
  return  combination(n-1, k-1) + combination(n-1, k); 
}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> s;
		if(c1.find(s[0]) == c1.end()){
			++c1[s[0]];
			c[s[0]] = true;
		}
		else if (c2.find(s[0]) == c2.end()){
			++c2[s[0]];
			c[s[0]] = false;
		}
		else if(c[s[0]]){
			++c2[s[0]];
			c[s[0]] = false;
		}
		else{
			++c1[s[0]];
			c[s[0]] = true;
		}
	}
	//cout << "dsaigfiuadsgf" << endl;
	int x = 0;
	for (const auto &c : c1){
		//cout << c.first << " " << c.second << endl;
		if(c.second > 1)
			x += combination(c.second, 2);
	}
	//cout << "FDSFSDF" << endl;
	for (const auto &c : c2){
		//cout << c.first << " " << c.second << endl;
			if(c.second > 1)
		x += combination(c.second, 2);
	}

	cout << x << endl;
    return 0;
}