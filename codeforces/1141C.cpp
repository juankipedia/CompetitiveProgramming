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

const int MAX = 2e5+5;
long long q[MAX], p[MAX] = {0};
int m[MAX] = {false};
int main() {
	io_boost;
	size_t n;
	cin >> n;
	
	for (size_t i = 0; i < n - 1; ++i) cin >> q[i];
	
	long long x = 0;
	for (int i = 1; i < n; ++i){
		p[i] = p[i-1] + q[i-1]; 
		x = min(x, p[i]);
	}
	
	for (int i = 0; i < n; ++i){
		p[i] -= x; 
		if(p[i] < n) m[p[i]]++;
	}
	for (int i = 0; i < n; ++i){if(m[i] != 1){cout << -1 << endl; return 0;}} 
	for (int i = 0; i < n; ++i) cout << p[i] + 1 << " ";
	cout << endl;
    return 0;
}