# include <iostream>
# include <vector>
# include <algorithm>
# include <iomanip>
using namespace std;
int main()
{
 	std::vector<double> cases;
 	unsigned int aux;
	do{

		unsigned int f, r, aux;
		std::vector<unsigned int> vaux1, vaux2, vaux3;
		cin >> f;
		if (f == 0)
		  break;
		cin >> r;
		for (unsigned int i = 0; i < f; ++i){
			cin >> aux;
			vaux1.push_back(aux);
		}
		for (unsigned int j = 0; j < r; ++j){
			cin >> aux;
			vaux2.push_back(aux);
		}

		std::vector<double> ratios;
		for (unsigned int i = 0; i < f; ++i)
		{
			for (unsigned int j = 0; j < r; ++j){
				ratios.push_back(static_cast<double>(vaux1[i]) / static_cast<double>(vaux2[j]));
			}		
		}
		vaux1.clear(), vaux2.clear();
		sort(ratios.begin(), ratios.end());
		std::vector<double> spreads;
		for (unsigned int i = ratios.size() - 1; i > 0; i -= 1)
			spreads.push_back(ratios[i] / ratios[i - 1]);
		ratios.clear();
		sort(spreads.begin(), spreads.end());
		cases.push_back(spreads[spreads.size() - 1]);	

	}while(true);

	for(double elem : cases)
		cout << setprecision(2) <<  fixed << elem << "\n";
	return 0;
}