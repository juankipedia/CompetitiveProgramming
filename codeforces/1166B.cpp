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

pair<int, int> printDivisors(int n){  
    for (int i=1; i<=sqrt(n); i++){ 
        if (n%i == 0){ 
            if (n/i == i){
            	if(i >= 5)
                	return make_pair(i,i);
            }
            else{
            	if(i >= 5 and n/i >= 5)
                return make_pair(i, n/i); 
            }
        } 
    }

    return make_pair(0,0); 
} 

int k;

int main() {
	char v[5] = {'a', 'e', 'i', 'o', 'u'};
	cin >> k;
	auto p = printDivisors(k);
	if(p.first == 0 and p.second == 0){
		cout << -1 << endl;
		return 0;
	}

	char w[p.first][p.second];
	char d_w[5][5] = {
		{'a', 'e', 'i', 'o', 'u'},
		{'e', 'a', 'o', 'u', 'i'},
		{'i', 'o', 'u', 'e', 'a'},
		{'u', 'i', 'e', 'a', 'o'},
		{'o', 'u', 'a', 'i', 'e'}
	};
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			w[i][j] = d_w[i][j];
		}
	}

	for (int j = 5; j < p.second; ++j){
		for (int i = 0; i < p.first; ++i){
			w[i][j] = v[(i % 5)] ; 
		}
	}

	for (int i = 5; i < p.first; ++i){
		for (int j = 0; j < 5; ++j){
			w[i][j] = v[(j % 5)];
		}
	}
	
	for (int i = 0; i < p.first; ++i){
		for (int j = 0; j < p.second; ++j){
			cout << w[i][j];
		}
	}
	cout << endl;
    return 0;
}