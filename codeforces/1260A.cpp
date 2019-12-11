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

int n, ci, sumi;

int main() {
	io_boost;
	cin >> n;
	while(n--){
		cin >> ci >> sumi;
		if(sumi % ci){
			if(sumi < ci){
				cout << sumi << endl;
			}
			else{
				int f = (sumi + ci - 1)/ci;
				int r = 0;
				for (int i = 0; i < ci; ++i){
					if(sumi % (ci - i)){
						r += f * f;
						sumi -= f;
					}
					else{
						r += (sumi / (ci - i)) * (sumi / (ci - i)) * (ci - i);
						break;
					}
				}
				cout << r << endl;
			}
		}
		else{
			cout << (sumi / ci) * (sumi / ci) * ci << endl;
		}
	}
    return 0;
}