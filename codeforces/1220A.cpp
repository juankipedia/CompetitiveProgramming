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

int n, o, z;
string s;
int m[5];
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i){
		if(s[i] == 'z')m[0]++;
		if(s[i] == 'e')m[1]++;
		if(s[i] == 'r')m[2]++;
		if(s[i] == 'o')m[3]++;
		if(s[i] == 'n')m[4]++;
	}

	o = m[4];
	z = m[0];

	for (int i = 0; i < o; ++i){
		cout << 1 << " ";
	}

	for (int i = 0; i < z; ++i){
		cout << 0 << " ";
	}

	cout << endl;

    return 0;
}