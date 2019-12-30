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

int q;
string p;

int main() {
	cin >> q;
	
	while(q--){
		cin >> p;
		int L = 0, R = 0, D = 0, U = 0, V = 0, H = 0;
		for (int i = 0; i < p.length(); ++i){
			if(p[i] == 'L') L++;
			else if(p[i] == 'R') R ++;
			else if(p[i] == 'D') D ++;
			else U ++;
		}
		V = min(U, D);
		H = min(L, R);
		if(V == 0){
			if(H != 0){
				cout << 2 << endl << "LR" << endl;
				continue;
			}
		}
		if(H == 0){
			if(V  != 0){
				cout << 2 << endl << "UD" << endl;
				continue;
			}
		}
		cout << V * 2 + H * 2 << endl;
		for (int i = 0; i < V; ++i)
			cout << "U";
		for (int i = 0; i < H; ++i)
			cout << "L";
		for (int i = 0; i < V; ++i)
			cout << "D";
		for (int i = 0; i < H; ++i)
			cout << "R";
		cout << endl;
	}	
    return 0;
}