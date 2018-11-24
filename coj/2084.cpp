# include <bits/stdc++.h>
using namespace std;


long long unsigned int solve(vector<string> &m, int i, int j, const long long unsigned int &n){
	if(i < 0 or j < 0 or i >= n or j >= n){
		return 0;
	}
	if(m[i][j] == 's')
		return 0;
	long long unsigned int s = 1;
	m[i][j] = 's';
	s += solve(m, i - 1, j - 1, n);
	s += solve(m, i - 1, j + 1, n);
	s += solve(m, i - 1, j, n);
	s += solve(m, i, j - 1, n);
	s += solve(m, i, j + 1, n);
	s += solve(m, i + 1, j - 1, n);
	s += solve(m, i + 1, j + 1, n);
	s += solve(m, i + 1, j, n);
	return s;
}


int main(){
	long long unsigned int n;
	while(cin >> n and n!= 0){
		vector<string> m;
		string str;
		long long unsigned int s = 0, b = 0;
		for (long long unsigned int i = 0; i < n; ++i){
			cin >> str;
			m.push_back(str);
		}

		vector<long long unsigned int> i_l;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if(m[i][j] == 'l'){
					i_l.push_back(solve(m, i, j, n));
				}
			}
		}

		if(i_l.size() >= 1){
			s = i_l[0]; b = i_l[0]; 
			for (long long unsigned int i = 1; i < i_l.size(); ++i){
				if(i_l[i] > b)
					b = i_l[i];
				if(i_l[i] < s)
					s = i_l[i];		
			}
		}

		cout << i_l.size() << " " << s << " " << b << endl; 
	}

}