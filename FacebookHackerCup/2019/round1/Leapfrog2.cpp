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

int T, b, e;
string s;

bool check(){
	if(b > e - 1) return false;
	else if(e % 2 == 0 ){
		if(b >= e / 2) return true;
		else return false;
	}
	else{
		if(b >= e / 2 + 1)return true;
		else return false;
	}
}

int main() {
	cin >> T;
	for(int k = 1; k <= T; k++){
		cin >> s;
		e = s.length() - 1;
		b = 0;
		for (int i = 0; i < s.length(); ++i){
			if(s[i] == 'B') b++; 
		}

		if(e == 1){
			cout << "Case #" << k << ": ";
			cout << 'N' << endl;
			continue;
		}

		if(check()){
			cout << "Case #" << k << ": ";
			cout << 'Y' << endl;
			continue;
		}
		
		if(b > e - 1 or e < 4 or b < 2){
			cout << "Case #" << k << ": ";
			cout << 'N' << endl;
			continue;
		}
		
		cout << "Case #" << k << ": ";
		cout << 'Y' << endl;
		
	}
    return 0;
}