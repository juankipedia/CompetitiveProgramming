# include <bits/stdc++.h>
using namespace std;

int main(){
	double sum = 0;
	double aux;
	for (unsigned int i = 0; i < 12; ++i){
		cin >> aux;
		sum += aux;
	}	

	cout << setprecision(2) << fixed << "$" << sum / 12 << "\n";
	return 0;
}