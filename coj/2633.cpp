# include <bits/stdc++.h>
using namespace std;

int main(){
	
	unsigned int n;
	double max = 0;
	double pi = 3.14159;
	cin >> n;
	for (unsigned int i = 0; i < n; ++i){
		char aux;
		cin >> aux;
		if (aux == 'C'){
			double r, h;
			cin >> r >> h;
			double v = (pi / 3) * r * r * h;
			if (v >= max)
				max = v;
		}
		else if(aux == 'L'){
			double r, h;
			cin >> r >> h;
			double v = pi * r * r * h;
			if (v >= max)
				max = v;
		}
		else{
			double r;
			cin >> r;
			double v = 4 * (pi / 3) * r * r * r; 
			if (v >= max)
				max = v;
		}
	}	

	cout << setprecision(3) << fixed << max << "\n";
	return 0;
}