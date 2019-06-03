#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


const int MAXN = 100001;

int n;

ui a[MAXN];
int e;
int o;


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] % 2 == 0) e++;
		else o++;
	}

	
	if(e == n or o == n){
		for (int i = 0; i < n; ++i){
			cout << a[i] << " ";
		}
		cout << endl;
		
		return 0;
	}

	sort(a, a+n);
			for (int i = 0; i < n; ++i){
			cout << a[i] << " ";
		}
		cout << endl;
    return 0;
}