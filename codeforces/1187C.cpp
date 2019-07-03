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

int n, m;

int main() {
	cin >> n >> m;
	int a[n+1];
	for (int i = 1; i <= n; ++i){
		a[i] = n - i + 1;
	}

	int t, l, r;
	vector<pair<int, int> > o, u;
	while(m--){
		cin >> t >> l >> r;
		if(t) o.push_back(make_pair(l,r));
		else u.push_back(make_pair(l,r));
	}

	sort(o.begin(),o.end());

	for (int i = 0; i < o.size(); ++i){
		for (int j = o[i].first + 1; j <= o[i].second ; ++j){
			a[j] = a[o[i].first];
		}
	}

	for (int i = 0; i < u.size(); ++i){
		bool d = false;
		for (int j = u[i].first + 1; j <= u[i].second ; ++j){
			if(a[j - 1] > a[j])
				d = true;
		}

		if(!d){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";

	cout << endl;
    return 0;
}