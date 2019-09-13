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
ulli n, m, r;
vector<int> digits[10];
int sum[10];
int main() {
	cin >> q;
	while(q--){
		cin >> n >> m;
		r = 0;
		if(digits[m % 10].size() == 0){
			for (int i = 1; (i * m) % 10 != 0; ++i){
				digits[m % 10].push_back((i*m)%10);
				sum[m % 10] += (i*m)%10;
			}
			digits[m % 10].push_back(0);
		}

		
		ulli n_t = n/m;
		ulli k = n_t / digits[m % 10].size();
		r += sum[m % 10] * k;
		n_t -= k * digits[m % 10].size();
		for (int i = 0; i < n_t; ++i){
			r += digits[m % 10][i % digits[m % 10].size()];
		}
		cout << r << endl;
	}
    return 0;
}