# include <iostream>
# include <vector>
# include <map>
# include <algorithm>

using namespace std;

int main()
{
	unsigned int test_cases;
	cin >> test_cases;
	unsigned int results[test_cases];
	for (unsigned int i = 0; i < test_cases; ++i)
	{
		unsigned int n, v, e;
		cin >> n;
		unsigned int voted[n], excluded[n];
		for (unsigned int j = 0; j < n; ++j) excluded[j] = voted[j] = 0;
		
		cin >> v;
		unsigned int aux;
		for (unsigned int j = 0; j < v; ++j){
			cin >> aux;
			voted[aux] ++;			
		}

		cin >> e;
		for (unsigned int j = 0; j < e; ++j){
			cin >> aux;
			excluded[aux] ++;			
		}		
		
		unsigned int max_e = excluded[0];
		for (unsigned int j = 1; j < n; ++j){
			if (excluded[j] > max_e)
				max_e = excluded[j];
		}

		std::vector<unsigned int> e_max;
		for (unsigned int j = 0; j < n; ++j){
			if (excluded[j] == max_e){
				e_max.push_back(j);
			}
		}


		if(e_max.size() == 1)
			results[i] = e_max[0];
		else{

			max_e = voted[e_max[0]];
			for (unsigned int j = 0; j < e_max.size(); ++j)
			{
				if(voted[e_max[j]] > max_e) max_e = voted[e_max[j]];
			}
			std::vector<unsigned int> r;
			for (unsigned int j = 0; j < e_max.size(); ++j)
			{
				if(voted[e_max[j]] == max_e)r.push_back(e_max[j]);
			}
			if (r.size() == 1)
			{
				results[i] = r[0];
			}
			else{
				results[i] = r[0];
				for (unsigned int j = 1; j < r.size(); ++j)
					if (r[j] < results[i])
						results[i] = r[j];
			}
		}
	

	}

	for (unsigned int i = 0; i < test_cases; ++i)
	{
		cout << results[i] << "\n";
	}
	return 0;
}