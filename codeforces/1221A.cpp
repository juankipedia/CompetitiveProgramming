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

int q,  n;
ulli sp;

int main() {
	cin >> q;
	while(q --){
		cin >> n;
		vector<int> s;
		bool f = false;
		for (int i = 0; i < n; ++i){
			cin >> sp;
			if(sp < 2048) s.push_back(log2(sp));
			else if(sp == 2048) f = true;
		}
		if(f){
			cout << "YES" << endl;
			continue;
		}

		bool v[11] = {false};
		for (int i = 0; i < s.size(); ++i){
			if(v[s[i]]){
				for (int j = s[i]; j < 11; ++j){
					if(v[j]){
						v[j] = false;
						if(j == 10){
							f = true;
							break;
						}
					}
					else{
						v[j] = true;
						break;
					}
				}
			}
			else v[s[i]] = true;

			if(f) break;
		}

		if(f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    return 0;
}