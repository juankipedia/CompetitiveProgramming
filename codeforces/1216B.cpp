#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


int n;
pair<int, int> a[1000];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a[i].first;
		a[i].second = i + 1;
	}

	sort(a, a+ n, std::greater<pair<int, int>>());

	int r = 0;
	for (int i = 0; i < n; ++i){
		r += a[i].first * i + 1;
	}
	cout << r << endl;
	for (int i = 0; i < n; ++i){
		cout << a[i].second << " ";
	}
	cout << endl;
    return 0;
}