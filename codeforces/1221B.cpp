#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;


int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (i % 2 == 0)
				if (j % 2 == 0)
					cout << "W";
				else
					cout << "B";
			else
				if (j % 2 == 0)
					cout << "B";
				else
					cout << "W";
		}
		cout << endl;
	}
	
    return 0;
}