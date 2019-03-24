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
	int n, m, k;
	cin >> n >> m >> k;
	std::vector<string> t;
	unordered_map<char, int> c;
	string w;
	for (int i = 0; i < n; ++i){
		cin >> w;
		for (const char & e: w){
			++c[e];
		}
	}
	for (int i = 0; i < m; ++i){
		cin >> w;
		string t_w = "";
		for (const char & e: w){
			t_w += (((e - 'a') + k) % 26) + 'a';
		}
		t.push_back(t_w);
	}

	for(const string &s: t){
		for (const char & e: s){
			if(c.find(e) == c.end() or c[e] == 0){
				cout << "It is gonna be daijoubu." << endl;
				return 0;
			}
			else{
				c[e]--;
			}
		}
	}

	cout << "Make her kokoro go doki-doki!" << endl;

    return 0;
}