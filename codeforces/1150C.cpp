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
	int n;
	cin >> n;
	int e;
	int one = 0, two = 0;
	for (int i = 0; i < n; ++i){
		cin >> e;
		if(e == 1)
			one ++;
		else
			two ++;
	}
	
	if(two == 0){
		for (int i = 0; i < one; ++i) cout << 1 << " ";
	}
	else if (one == 0){
		for (int i = 0; i < two; ++i) cout << 2 << " ";
	}
	else{
		cout << 2 << " " << 1 << " ";
		two--; one--;
		for (int i = 0; i < two; ++i)
			cout << 2 << " ";

		for (int i = 0; i < one; ++i)
			cout << 1 << " ";
	}

	cout << endl;
    return 0;
}