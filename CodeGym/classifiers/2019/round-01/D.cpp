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

std::vector<int> f;
void factors(int & x){ 
    for (int i = 1; i * i <= x; i++){
        if (x % i == 0 and i != 1){
        	f.push_back(i);
        	f.push_back(x/i);
        } 
    }
    f.push_back(x);
}

bool common_factor(int &l){
	for (const int &e : f)
		if(l % e == 0)
			return true;
	return false;
}
int main() {
	int n, m, x, l;
	cin >> n >> m >> x;
	int r = 0;
	factors(x);
	//for (const int &e : f) cout << e << " ";
	//	cout << endl;
	for (int i = 0; i < n; ++i){
		for (int i = 0; i < m; ++i){
			cin >> l;
			if(common_factor(l)){
				//cout << l << endl;
				r++;
			}
		}
	}
	cout << r << endl;
	return 0;
}