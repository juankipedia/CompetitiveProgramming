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

bool t[4][4] = {false};

void clean(int cl){
bool c_r = true;
	if(cl){
		
		for (int i = 0; i < 4; ++i){
			if(t[0][i] == false){
				c_r = false;
				break;
			}
		}
		if(c_r)
			for (int i = 0; i < 4; ++i) {t[0][i] = false; t[1][i] = false;} 
	}
	else{
		for (int i = 0; i < 4; ++i){
			if(t[2][i] == false){
				c_r = false;
				break;
			}
		}
		if(c_r)
			for (int i = 0; i < 4; ++i) t[2][i] = false;
	}
}

void solve(bool c){
	if(c){
		
		for (int j = 0; j < 4; ++j){
			if(t[0][j] == false and t[1][j] == false){
				cout << 1 << " " << j + 1 << endl;
				t[0][j] = t[1][j] = true;
				clean(c);
				return;
			}
		}
		
	}
	else{
		
		for (int j = 0; j < 3; ++j){
			if(t[2][j] == false and t[2][j + 1] == false){
				cout << 3 << " " << j + 1 << endl;
				t[2][j] = t[2][j + 1] = true;
				clean(c);
				return;
			}
		}
		
	}
}

void print(){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j)
			cout << t[i][j];
		cout << endl;
	}
}

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); ++i){
		if(s[i] == '1')
			solve(false);
		else
			solve(true);
		//print();
	}
	return 0;
}