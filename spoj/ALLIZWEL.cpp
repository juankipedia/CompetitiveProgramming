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
const int MAX = 100;
int T, R, C;
vector<string> M(MAX);
string aiw;
bool _has_path(int i, int j, int pos, set<pair<int, int>> memo){
	if(i < 0 or i >= R or j < 0 or j >= C)
		return false;

	if(pos >= aiw.size())
		return true;

	if(memo.find(make_pair(i, j)) != memo.end()) return false;
	memo.insert(make_pair(i, j));

	if(M[i][j] != aiw[pos]) return false;



	if(_has_path(i - 1, j, pos + 1, memo)) return true;
	if(_has_path(i - 1, j - 1, pos + 1, memo)) return true;
	if(_has_path(i - 1, j + 1, pos + 1, memo)) return true;
	if(_has_path(i, j - 1, pos + 1, memo)) return true;
	if(_has_path(i, j + 1, pos + 1, memo)) return true;
	if(_has_path(i + 1, j, pos + 1, memo)) return true;
	if(_has_path(i + 1, j + 1, pos + 1, memo)) return true;
	if(_has_path(i + 1, j - 1, pos + 1, memo)) return true;

	return false;
}

bool has_path(){
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			if(M[i][j] == 'A'){
				set<pair<int, int>> memo;
				if(_has_path(i, j, 0, memo))
					return true;
			}
		}
	}

	return false;
}

int main() {
	aiw = "ALLIZZWELL";
	cin >> T;
	while(T--){
		cin >> R >> C;
		for (int i = 0; i < R; ++i)
			cin >> M[i];

		if(has_path())
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    return 0;
}