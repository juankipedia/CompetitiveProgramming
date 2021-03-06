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


int t, n, r, p, pf;
string s;

int main() {
	cin >> t;
	while(t--){
		cin >> n;
		cin >> s;
		r = 0; p = -1; 
		pf = -1;
		for (int i = 0; i < n; ++i){
			if(s[i] == '0') r++;
			else{
				if(p == -1) p = i; 
				r += 2; 
				pf = i;
			}
		}
		if(p != -1) r = max(r, (n - p) * 2);
		if(pf != -1) r = max(r, (pf + 1) * 2);
		cout << r << endl;
	}
    return 0;
}