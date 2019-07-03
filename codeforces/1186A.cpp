#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int n, m, k;

int main() {
	cin >> n >> m >>k;
	if(m >= n and k >= n) cout << "Yes" <<endl;
	else cout << "No" << endl;
    return 0;
}