# include <iostream>
# include <algorithm>

using namespace std;

int main()
{
	unsigned int cases;
	cin >> cases;
	unsigned int r[cases];
	for (unsigned int i = 0; i < cases; ++i)
	{
		unsigned int s;
		cin >> s;
		unsigned int p[s];
		for (unsigned int j = 0; j < s; ++j)
		{
			cin >> p[j];
		}
		
		sort(p, p + s);

		if(!(s % 2))
			r[i] = (p[s / 2 - 1] - p[0]) * 2 + (p[s - 1] - p[s / 2 - 1]) * 2;
		else
			r[i] = (p[static_cast<unsigned int>(s / 2)] - p[0]) * 2 + 
					(p[s - 1] - p[static_cast<unsigned int>(s / 2)]) * 2; 
	}

	for (unsigned int i = 0; i < cases; ++i)
		cout << r[i] << "\n";
		
	return 0;
}