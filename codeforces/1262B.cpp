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

int t, n, q[100000];
 
int main() {
	cin >> t;
	while(t--){
		cin >> n;
		vector<bool> m(n + 1, false);
		vector<int> r;
		for (int i = 0; i < n; ++i) cin >> q[i];
		
		r.push_back(q[0]);
		m[q[0]] = true;
		int j = (q[0] == 1) ? 2: 1;
		for (int i = 1; i < n; ++i){
			if(not m[q[i]]){
				r.push_back(q[i]);
				m[q[i]] = true;
			}
			else{
				while(m[j] and j < q[i]){
					j++;
				}
				if(j >= q[i]){
					r.push_back(-1);
					break;
				}
				r.push_back(j);
				m[j] = true;
			}
		}

		if(r[r.size() - 1] != -1){
			for(const int &p: r) cout << p << " ";
			cout << endl;
		}
		else cout << -1 << endl;

	}
    return 0;
}