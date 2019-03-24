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

int main() {
	int n;
	cin >> n;
	int x, y0, y1, y2, mi, ma;
	vector<pair<int, bool> > p;
	for (int i = 0; i < n; ++i){
		cin >> x >> y0 >> x >> y1 >> x >> y2;
		mi = min(min(y0, y1), y2);
		ma = max(max(y0, y1), y2);
		p.push_back(make_pair(mi, true)); p.push_back(make_pair(ma, false));
	}
	sort(p.begin(), p.end(), [](pair<int, bool> & a, pair<int, bool> & b){
		if(a.first == b.first)
			return a.second == true;
		else
			return a.first < b.first;
	});
	int c = 0, r = 0;
	for (const auto &e : p){
		if(e.second == true)
			c++;
		else{
			r = max(c, r);
			c--;
		}
	}
	cout << r << endl;
}