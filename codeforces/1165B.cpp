#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin >> a[i]; 
	}
	sort(a, a + n);
	int d = 0;
	for (int i = 0; i < n; ++i){
		if(a[i] >= d + 1)
			d++;
	}

	cout << d << endl;
    return 0;
}