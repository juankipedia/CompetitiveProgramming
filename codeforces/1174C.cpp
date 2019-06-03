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
typedef std::numeric_limits< double > dbl;
const int MAXN = 100002;
int n;
int a[MAXN];
int main() {
	cin >> n;
	int k = 1;
	for (int i = 2; i <= n; ++i){
		if(a[i] == 0){
			for (int j = i, h = 2; j <= n; j = i * h, h++){
				if(a[j] == 0)
					a[j] = k;
			}
			k++;
		}
		//cout << endl;
		
	}

	for (int i = 2; i <= n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
    return 0;
}