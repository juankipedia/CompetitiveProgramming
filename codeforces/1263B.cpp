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

int t, n, r;
string c[10];
int main() {
	io_boost;
	cin >> t;
	while(t--){
		cin >> n;
		map<string, int> m;
		for (int i = 0; i < n; ++i){
			cin >> c[i];
			++m[c[i]];
		}
		vector<string> sol;
		r = 0;
		set<string> ms;
		for (const auto &p: m) r += p.second - 1;
		cout << r << endl;
		for (int w = 0; w < n; w++){

			string s = c[w];
			int j = s.length() - 1;

			if(ms.find(s) == ms.end()){
				cout << s << endl;
				ms.insert(s);
				continue;
			}
			ms.insert(s);
			while(m.find(s) != m.end() or ms.find(s) != ms.end()){
				s[j]++;
				if(s[j] > '9')
					s[j] = '0';
			}
			ms.insert(s);
			cout << s << endl;
		}
	}
    return 0;
}