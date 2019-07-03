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

int a[5] = {1, 2, 3, 4, 5};

int main() {
	for (int i = 0; i < 1; ++i){
		for (int i = 1; i <= 5; ++i){
			for (int j = 0; j <= 5 - i; j++){
				for (int k = j; k < j + i ; ++k){
					cout << a[k] << " ";
				}
				cout << endl;
			}
		}
	}
    return 0;
}