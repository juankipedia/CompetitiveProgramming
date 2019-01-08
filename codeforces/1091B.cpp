#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
int main() {
	lli n;
	cin >> n;
	pair<lli, lli> o[n], c[n];
	set<pair<lli, lli> > r;
	lli a, b;
	for (lli i = 0; i < n; ++i){
		cin >> a >> b;
		o[i] = make_pair(a, b);
	}

	for (lli i = 0; i < n; ++i){
		cin >> a >> b;
		c[i] = make_pair(a, b);
	}

	for (lli i = 0; i < n; ++i) r.insert(make_pair(o[i].first + c[0].first, o[i].second + c[0].second));

	for (lli i = 1; i < n; ++i){
		set<pair<lli, lli> > r_i;
		for (lli j = 0; j < n; ++j){
			if (r.find(make_pair(o[j].first + c[i].first,o[j].second + c[i].second)) != r.end())
				r_i.insert(make_pair(o[j].first + c[i].first , o[j].second + c[i].second));
		}
		r.clear();
		r.insert(r_i.begin(), r_i.end());
	}
	cout << r.begin()->first << " " << r.begin()->second << endl;
    return 0;
}