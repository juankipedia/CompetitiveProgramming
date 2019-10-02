#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;

int q, n;
string s1,s2;

bool type1(char c){
	if(c == '3' or c == '4' or c == '5' or c == '6')
		return false;
	return true;
}

bool solve(int i, int j, int o){
	
	
	if(j == n - 1){
		if(i == 0 and not type1(s1[j]) and not type1(s2[j]))
			return true;
		if(i == 1 and type1(s2[j]))
			return true;

		return false;
	}

	if(o == 0 and i == 0)
		return solve((type1(s1[j]))?(0):(1), (type1(s1[j]))?(j+1):(j), (type1(s1[j]))?(0):(2));
	if(o == 1 and i == 0){
		if(type1(s1[j])) return false;
		return solve(i, j+1, 0);
	}
	if(o == 0 and i == 1)
		return solve((type1(s2[j]))?(1):(0), (type1(s2[j]))?(j+1):(j), (type1(s2[j]))?(0):(1));
	if(o == 2 and i == 1){
		if(type1(s2[j])) return false;
		return solve(i, j+1, 0);
	}

	return false;

}

int main() {
	cin >> q;
	while(q--){
		cin >> n;
		cin >> s1;
		cin >> s2;
		if(solve(0, 0, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    return 0;
}