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
vector<string> m;
int n;

bool up(int i, int j){
	if(i + 1 >= n or i + 2 >= n or j - 1 < 0 or j + 1 >= n)
		return false;

	if(m[i + 1][j] == '.' and m[i + 2][j] == '.' and 
	   m[i + 1][j - 1] == '.' and m[i + 1][j + 1] == '.'){
		m[i + 1][j] = '#'; m[i + 2][j] = '#'; m[i + 1][j - 1] = '#'; m[i + 1][j + 1] = '#';
		return true;
	}

	return false;
}


bool center(int i, int j){
	if(i + 1 >= n or i - 1 < 0 or j - 1 < 0 or j + 1 >= n)
		return false;

	if(m[i + 1][j] == '.' and m[i - 1][j] == '.' and 
	   m[i][j - 1] == '.' and m[i][j + 1] == '.'){
		m[i + 1][j] = '#'; m[i - 1][j] = '#'; m[i][j - 1] = '#'; m[i][j + 1] = '#';
		return true;
	}
	return false;
}

bool down(int i, int j){
	if(i - 1 < 0 or i - 2 < 0 or j - 1 < 0 or j + 1 >= n)
		return false;

	if(m[i - 1][j] == '.' and m[i - 2][j] == '.' and 
	   m[i - 1][j - 1] == '.' and m[i - 1][j + 1] == '.'){
		m[i - 1][j] = '#'; m[i - 2][j] = '#'; m[i - 1][j - 1] = '#'; m[i - 1][j + 1] = '#';
		return true;
	}

	return false;
}

bool left(int i, int j){
	if(i - 1 < 0 or i + 1 >= n or j + 1 >= n or j + 2 >= n)
		return false;

	if(m[i][j + 1] == '.' and m[i][j + 2] == '.' and 
	   m[i - 1][j + 1] == '.' and m[i + 1][j + 1] == '.'){
		m[i][j + 1] = '#'; m[i][j + 2] = '#'; m[i - 1][j + 1] = '#'; m[i + 1][j + 1] = '#';
		return true;
	}

	return false;
}

bool rigth(int i, int j){
	if(i - 1 < 0 or i + 1 >= n or j - 1 < 0 or j - 2 < 0)
		return false;

	if(m[i][j - 1] == '.' and m[i][j - 2] == '.' and 
	   m[i - 1][j - 1] == '.' and m[i + 1][j - 1] == '.'){
		m[i][j - 1] = '#'; m[i][j - 2] = '#'; m[i - 1][j - 1] = '#'; m[i + 1][j - 1] = '#';
		return true;
	}

	return false;
}

int main() {

	cin >> n;

	string r;
	for (int i = 0; i < n; ++i){
	 	cin >> r;
	 	m.push_back(r);
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if(m[i][j] == '.'){
				if(not (up(i, j) or center(i, j) or down(i, j) or left(i, j) or rigth(i, j))){
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}

	cout << "YES" << endl;
    return 0;
}