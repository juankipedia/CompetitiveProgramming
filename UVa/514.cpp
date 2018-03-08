# include <bits/stdc++.h>
using namespace std;

int main()
{
	unsigned int n;
	while(cin >> n and n != 0){
		unsigned int coach = 1;
		while(coach != 0){
			int order[n];
			for (unsigned int i = 0; i < n; ++i){
				cin >> coach;
				if(coach == 0)
					break;
				else{
					order[i] = coach;
				}	
			}

			int c_coach = 1, j = 0;
			stack<unsigned int> station;
			while(c_coach <= n){
				station.push(c_coach);

				while(!station.empty() && station.top() == order[j]){
					station.pop();
					j++;
					if(j >= n ) 
						break;
				}

				c_coach++;
			}

			if(coach != 0){
				if(station.empty())
					cout << "Yes\n";
				else
					cout << "No\n";
			}
		}
		cout << "\n";
	}
	return 0;
}