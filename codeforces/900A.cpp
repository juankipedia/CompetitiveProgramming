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
	int N;
	cin >> N;
	lli n = 0, p = 0, x, y;
	for (int i = 0; i < N; ++i){
		cin >> x >> y;
		if(x < 0) n++;
		else p++;
	}

	if(p == 1 and n >= 1){
		cout << "Yes" << endl;
		return 0;
	}
	else if (n == 1 and p >= 1){
		cout<< "Yes" << endl;
		return 0;
	}

	else if (p == 0 and n >= 1){
		cout<< "Yes" << endl;
		return 0;
	}

	else if (n==0 and p>= 1){
		cout<< "Yes" << endl;
		return 0;
	}


	cout << "No" << endl;
    return 0;
}