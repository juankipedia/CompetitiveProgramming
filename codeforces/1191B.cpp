#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


int main() {
	vector<string> t; t.push_back(""); t.push_back(""); t.push_back("");
	cin >> t[0] >> t[1] >> t[2];
	if(t[0] == t[1] and t[1] == t[2]){
		cout << 0 << endl;
		return 0;
	}

	sort(t.begin(), t.end());
	if(t[0][1] == t[1][1] and t[1][1] == t[2][1] and t[0][0] + 1 == t[1][0] and t[1][0] + 1 == t[2][0]){
		cout << 0 << endl;
		return 0;
	}

	sort(t.begin(), t.end(), [](string &A, string &B){
		return A[1] < B[1];
	});

	if(t[0][1] == t[1][1]){
		if(t[0][0] + 1 == t[1][0] or t[0][0] == t[1][0] + 1 or t[0][0] == t[1][0] or
			t[0][0] + 2 == t[1][0] or t[0][0] == t[1][0] + 2
			)
			cout << 1 << endl;
		else 
			cout << 2 << endl;
	}
	else if(t[1][1] == t[2][1]){
		if(t[1][0] + 1 == t[2][0] or t[1][0] == t[2][0] + 1 or t[1][0] == t[2][0] or
			t[1][0] + 2 == t[2][0] or t[1][0] == t[2][0] + 2
			)
			cout << 1 << endl;
		else 
			cout << 2 << endl;
	}
	else
		cout << 2<< endl;
    return 0;
}