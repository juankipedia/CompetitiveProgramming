# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class criteria
{
public:
	bool operator () (size_t a, size_t b){
		return(b > a);
	}
	
};
int main()
{
	
	size_t escenaries;
	size_t items;
	std::vector<std::vector<size_t> > cases;
	cin >> escenaries;
	for (size_t i = 0; i < escenaries; ++i)
	{
		cin >> items;
		std::vector<size_t> v_aux;
		for (size_t j = 0; j < items; ++j)
		{
			size_t aux;
			cin >> aux;
			v_aux.push_back(aux);
		}
		cases.push_back(v_aux);
	}

	criteria c;

	for (size_t i = 0; i < escenaries; ++i)
	{
		sort(cases[i].begin(), cases[i].end());
		size_t sum = 0;
		for (int j = cases[i].size() - 3; j >= 0 ; j = j - 3)
		{
			//cout << cases[i][j];
			sum += cases[i][j];
		}
		cout << sum << "\n";
	}
	return 0;
}