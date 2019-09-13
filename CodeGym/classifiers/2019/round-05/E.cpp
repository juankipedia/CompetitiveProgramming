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

string w;
string a;

bool is_p(int i, int j){
	for (; ; i++, j--){
		if(i >= j)
			break;

		if(w[i] != w[j])
			return false;
	}

	return true;
}

int main() {
	cin >> w; 

	for (int i = 0, j = w.length() - 1; i < w.length(); ++i){
		if(is_p(i, j)){
			cout << w;
			for (int k = i - 1; k >= 0; k--){
				cout << w [k];
			}

			cout << endl;
			return 0;
		}
	}

    return 0;
}