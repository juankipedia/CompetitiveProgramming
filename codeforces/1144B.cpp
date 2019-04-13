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
	int a;
	vector_i o, e;
	for (int i = 0; i < n; ++i){
		cin >> a;
		if(a % 2 == 0) e.push_back(a);
		else o.push_back(a);
	}
	if(e.size() + 1 == o.size() or o.size() + 1 == e.size() or o.size() == e.size()){
		cout << 0 << endl;
		return 0;
	}
	sort(o.begin(), o.end(), greater<int>());
	sort(e.begin(), e.end(), greater<int>());

	if(e.size() > o.size()){
		size_t s = 0;
		for (int i = o.size() + 1; i < e.size(); ++i) s += e[i];
		cout << s << endl;
	}
	else{
		size_t s = 0;
		for (int i = e.size() + 1; i < o.size(); ++i) s += o[i];
		cout << s << endl;
	}
    return 0;
}