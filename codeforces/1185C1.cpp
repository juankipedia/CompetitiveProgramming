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
const int MAXN = 200000;
int t[MAXN], n, m;
ulli s[MAXN];
map<int, int, std::greater<int>> memo;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		cin >> t[i];
	}
	
	s[0] = t[0];
	for (int i = 1; i < n; ++i){
		s[i] = t[i] + s[i - 1];
	}

	cout << 0 << " ";
	++memo[t[0]];
	for (int i = 1; i < n; ++i){
		if(s[i]> m){
			int count = 0;
			ulli c = s[i - 1];
			//cout << endl << "entra " << i << " " << c << endl;

			for (const auto &p: memo){

				if(c - p.first * p.second + t[i] > m){
					c -= p.first * p.second;
					count += p.second;
					// <<  "hh" << p.first << endl;
					continue;
				}

				cout << (c - m + t[i] + p.first - 1)/ p.first + count << " "; 
				break;
				//techo(x/y) = piso((x+y-1)/y)
			 	//p.first * x >= c - m + t[i]
				
				
			}
		}
		else
			cout << 0 << " ";
		
		++memo[t[i]];
	}
	cout << endl;
    return 0;
}