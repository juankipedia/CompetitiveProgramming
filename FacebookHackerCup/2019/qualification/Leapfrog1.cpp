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
int main() {
	cin >> T;
	for(int k = 1; k <= T; k++){
		cin >> s;
		e = s.length() - 1;
		b = 0;
		for (int i = 0; i < s.length(); ++i){
			if(s[i] == 'B') b++; 
		}

		char r = 'Y';

		if(e == 1){
			cout << "Case #" << k << ": ";
			cout << 'N' << endl;
			continue;
		}

		for (int i = e - 1; i > 0; i -= 2){
			if(b == i){
				b = 0;
				break;
			}
			b--;
			if(b == 0){
				r = 'N';
				break;
			}
		}

		if(r == 'N' or b != 0){
			cout << "Case #" << k << ": ";
			cout << 'N' << endl;
		}
		else{
			cout << "Case #" << k << ": ";
			cout << 'Y' << endl;
		}
	}
    return 0;
}