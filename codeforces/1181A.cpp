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

ulli x, y, z, c, rx, ry;
int main() {
	cin >> x >> y >> z;
	c += x / z;
	c += y / z;
	rx = x % z;
	ry = y % z;

	c += (rx + ry) / z;
	if((rx + ry) / z != 0){
		cout << c << " " << z - max(rx, ry) << endl;
		return 0;
	}

	cout << c << " " << 0 <<endl;
    return 0;
}