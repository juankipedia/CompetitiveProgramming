#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> v_i;
typedef vector<long long int> v_lli;
typedef vector<unsigned int> v_ui;
typedef vector<unsigned long long int> v_ulli;
typedef set<int> s_i;
typedef set<long long int> s_lli;
typedef set<unsigned int> s_ui;
typedef set<unsigned long long int> s_ulli;
typedef unordered_set<int> u_s_i;
typedef unordered_set<long long int> u_s_lli;
typedef unordered_set<unsigned int> u_s_ui;
typedef unordered_set<unsigned long long int> u_s_ulli;

int main() {
	string e;
	int k;
	cin >> e;
	cin >> k;

	int s = 0;
	for (int i = 0; i < e.length(); ++i)
		if(e[i] == '?' or e[i] == '*')
			s++;
	int r_l = e.length() - s;
	if(r_l == k){
		for (int i = 0; i < e.length(); ++i) if(e[i] != '?' and e[i] != '*') cout << e[i];
		cout << endl;
	}
	else if(r_l < k){
		string res = "";
		for (int i = 0; i < e.length(); ++i){
			if(e[i] != '?' and e[i] != '*')
				res += e[i];
			else if(e[i] == '*' and r_l != k){
				for (int j = r_l; j < k; ++j)
					res += e[i - 1];
				r_l = k;
			}
		}
		if(res.length() == k)
			cout << res << endl;
		else{
			cout << "Impossible" << endl;
		}
	}
	else{
		//cout << "EPA" << endl;
		string res = "";
		for (int i = 0; i < e.length() - 1; ++i){
			if((e[i + 1] == '?' or e[i + 1] == '*') and r_l != k){
				r_l --;
				continue;
			}
			if(e[i] == '?' or e[i] == '*')
				continue;

			res += e[i];
		}
		if(e[e.length() - 1] != '?' and e[e.length() - 1] != '*')
			res += e[e.length() - 1];
		//cout << res << endl;
		if(res.length() == k)
			cout << res << endl;
		else{
			cout << "Impossible" << endl;
		}
	}

    return 0;
}