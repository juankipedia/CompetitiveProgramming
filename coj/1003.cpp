# include <iostream>
# include <vector>

using namespace std;

int main()
{
	
	unsigned int test_n;
	cin >> test_n;
	unsigned int results[test_n];
	for (unsigned int j = 0; j < test_n; ++j)
	{
		unsigned int n, m;
		cin >> n;
		cin >> m;
		unsigned int v[n];

		for (unsigned int i = 0; i < m; ++i)
		{
			for (unsigned int k = 0; k < n; ++k)
			{
				unsigned int aux;
				cin >> aux;
				if(i == 0)
					v[k] = aux;
				else
					v[k] += aux;

			}
		}

		unsigned int max = v[0];
		results[j] = 1;
		for (unsigned int i = 1; i < n; ++i){
			if(v[i] > max){
				max = v[i];
				results[j] = i + 1;
			}
		}
	}

	for (unsigned int i = 0; i < test_n; ++i)
	{
		cout << results[i] << "\n";
	}
	return 0;
}