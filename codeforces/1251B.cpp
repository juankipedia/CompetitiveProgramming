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

int q, n, ones, zeros, both, one, zero, perfect;
string s;
int main() {
	cin >> q;
	while(q--){
		cin >> n;
		both = one = zero = perfect = 0;
		for (int i = 0; i < n; ++i){
			cin >> s;
			ones = zeros = 0;
			for (int i = 0; i < s.length(); ++i) if(s[i] == '0') zeros++; else ones++;
			if(zeros % 2 == 0){
				if(ones % 2 == 0) perfect ++;
				else one ++;
			}
			else if(ones % 2 == 0) zero ++;
			else both++;
		}
		int r = 0;
		if(both % 2 == 0)r += both;
		else r += both - 1;
		both -= r;
		if(both > 0 and (one > 0 or zero > 0)) r+= both + one + zero + perfect;
		else r += one + zero + perfect;
		cout << r << endl;
	}
    return 0;
}

// if a string is palindrome with even 1s and even 0s there is nothing to do
// if a string is palindrome with even 1s and odd 0s we can give a 0
// if a string is palindrome with even 0s and odd 1s we can give a 1
// if a string is not a palindrome it can give a 1 or a 0