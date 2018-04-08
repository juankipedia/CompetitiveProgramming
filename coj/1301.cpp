# include <iostream>
# include <iomanip>
# include <cmath>
using namespace std;

# define PI 3.141592653589793115997963468544

int main(){
	double r;
	cin >> r;
	cout << setprecision(4) << fixed << (PI * r * r) - 5 * (1e-5) << "\n";
	cout << setprecision(4) << fixed << 2 * r * r << "\n";
	return 0;
}