# include <iostream>
using namespace std;
int main()
{
	unsigned int cases, aux;
	cin >> cases;
	unsigned int islands[cases][15];
	for (unsigned int i = 0; i < cases; ++i)
	{
		cin >> aux; 
		for (unsigned int j = 0; j < 15; ++j)
			cin >> islands[i][j];
	}

	unsigned int count = 0;
	for (unsigned int i = 0; i < cases; ++i)
	{
		for (unsigned int j = 0; j < 14; ++j)
		{
			if(islands[i][j] < islands[i][j + 1])
				count ++;
		}
		cout << i + 1 << " " << count << "\n";
		count = 0;
	}
	return 0;
}