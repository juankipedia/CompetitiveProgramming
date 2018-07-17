# include <bits/stdc++.h>

using namespace std;

int main(){
	double a[10] = {1,1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	double e = 2.5;
	cout << "n e \n";
	cout << "- -----------\n";
	cout << "0 1\n";
	cout << "1 2\n";
	cout << "2 2.5\n";
	for (int i = 3; i <= 9; ++i){
		e += 1.0 / a[i];
		cout << i << " ";
		cout << setprecision(9) << fixed << e << "\n";
	}
	return 0;
}