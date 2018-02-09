# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;

int main()
{
	unsigned int cases;
	cin >> cases;
	double r;
	double a[cases];
	for (unsigned int i = 0; i < cases; ++i)
	{
		cin >> r;
		a[i] = r * r * (acos(0) * 2.0 - 2);
	}
	for (unsigned int i = 0; i < cases; ++i)
		cout << fixed << setprecision(2) << a[i] << "\n";
	return 0;
}