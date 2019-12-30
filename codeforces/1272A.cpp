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

int q;
lli a, b, c, ap, bp, cp;

int main() {
	cin >> q;
	int mov[3] = {1, 0, -1};
	while(q--){
		cin >> a >> b >> c;
		lli mini = std::numeric_limits<lli>::max();
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				for (int k = 0; k < 3; ++k){
					ap = a + mov[i];
					bp = b + mov[j];
					cp = c + mov[k];
					mini = min(abs(ap - bp) + abs(ap - cp) + abs(bp - cp), mini);
				}
			}
		}
		cout << mini << endl;
	}	
    return 0;
}