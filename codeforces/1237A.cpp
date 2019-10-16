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

int n;
int a[13845];
int main() {
	cin >> n;
	int c = 0;
	for (int i = 0; i < n; ++i) cin >> a[i];

	bool t = true;
	for (int i = 0; i < n; ++i){
		if(abs(a[i]) % 2 != 0){
			if(a[i] > 0){
				if(t){
					cout << a[i] / 2 << endl;
					t = false;
				}
				else{
					t = true;
					cout << a[i] / 2  + 1<< endl;
				}
			}
			else{
				if(t){
					cout << a[i]/2 - 1 << endl;
					t = false;
				}
				else{
					cout << a[i]/2<< endl;
					t = true;
				}
			}
		}
		else cout << a[i] / 2 << endl;
	}
    return 0;
}