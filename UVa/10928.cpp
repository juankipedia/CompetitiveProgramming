# include <bits/stdc++.h>

using namespace std;

int main(){
	unsigned int n;
	cin >> n;
	for (unsigned int k = 0; k < n; ++k){
		unsigned int p;
		cin >> p;
		vector<unsigned int> g[p];
		vector<unsigned int> minors;
		unsigned int minor = p;
		for (unsigned int i = 0; i < p; ++i){
			unsigned int n_;
			char c;
			while(cin >> n_){
				c = getchar();
				g[i].push_back(n_);
				if(c == '\n')
					break;
			}
			if (g[i].size() < minor)
				minor = g[i].size();
		}
		for (unsigned int i = 0; i < p; ++i)
			if(g[i].size() == minor)
				minors.push_back(i + 1);

		for (unsigned int i = 0; i < minors.size() - 1; ++i)
			cout << minors[i] << ' ';
		cout << minors[minors.size() - 1]<< "\n";
		getchar();
		
	}
	return 0;
}