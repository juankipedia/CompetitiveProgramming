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

const int MAXN = 100000;
int n;
ulli a[MAXN];
ulli r[MAXN];

bool t(){
	if(r[n - 1] + r[1] <= r[0])
		return false;
	for (int i = 1; i < n - 1; ++i){
		if(r[i] >= r[i + 1] + r[i - 1])
			return false;
	}

	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n, std::greater<ulli>());
	r[0] = a[0];
	r[n - 1] = a[2]; 
	r[1]  = a[1];
	for (int i = 2; i < n - 1; ++i){
		r[i] = a[i + 1];
	}

	if(not t()){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	for (int i = 0; i < n; ++i){
		cout << r[i] << " ";
	}


	cout << endl;
    return 0;
}