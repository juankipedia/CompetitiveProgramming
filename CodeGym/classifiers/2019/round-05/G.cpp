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
 
int a[3], d[2][3], n, l, r;
int main() {
	cin >> n >> l >> r;
	l--;
	for(int i=0; i<3; i++)
		a[i]=(r+i)/3-(l+i)/3;
	d[0][0]=1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<3; j++)
			d[i%2^1][j]=0;
		for(int j=0; j<3; j++)
			for(int k=0; k<3; k++)
				d[i%2^1][(j+k)%3]=(d[i%2^1][(j+k)%3]+1LL*a[j]*d[i%2][k])%1000000007;
	}
	cout << d[n%2][0] << endl;
}