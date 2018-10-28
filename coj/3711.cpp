# include <iostream>
# include <vector>
# include <utility>
# include <unordered_map>
# include <tuple>
# include <cmath>
using namespace std;

void check(unsigned int &n){
	tuple<vector<bool>, vector<bool>, vector<bool> > m[n + 1];
	bool rows[n + 1][n];
	bool colums[n + 1][n];
	bool sub_grids[n + 1][n + 1];

	for (size_t i = 0; i < n + 1; ++i)
		sub_grids[i][n] = false;

	for (size_t i = 0; i < n + 1; ++i)
		for (size_t j = 0; j < n; ++j)
			sub_grids[i][j] = colums[i][j] = rows[i][j] = false;

	unsigned int v, s_g = static_cast<size_t>(sqrt(n));
	bool r = true;
	
	unsigned int colum = 1, row = 1, s_g_n = 0, counter = 0;
	for (unsigned int i = 0; i < n; ++i){
		if(i == s_g * row){
			counter ++;
			row ++;
		}
		colum = 0;
		s_g_n = s_g * counter;
		for (unsigned int j = 0; j < n; ++j){
			cin >> v;
			
			if(j == s_g * colum){
				s_g_n ++;
				colum ++;
			}
			
			if (rows[v][i] or colums[v][j] or sub_grids[v][s_g_n])
				r = false;
			else
				sub_grids[v][s_g_n] = colums[v][j] = rows[v][i] = true;
		}
	}

	if(r)
		cout << "yes\n";
	else 
		cout << "no\n";
	return;
}

int main (){
	unsigned int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		check(n);
	}
	return 0;
}