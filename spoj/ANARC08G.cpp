# include <bits/stdc++.h>
using namespace std;

int main(){
	size_t amount_t, m, amount, N, pos = 1;
	long long int amount_t2;
	while(cin >> N and N != 0){
		long long int amounts[N] = {0};
		amount_t = amount_t2 = 0;
		for (size_t i = 0; i < N; ++i){
			for (size_t j = 0; j < N; ++j){
				cin >> amount;
				amount_t += amount;
				amounts[j] += amount;
				amounts[i] -= amount;
			}
		}

		for (size_t i = 0; i < N; ++i)
			if(amounts[i] < 0) amount_t2 += amounts[i];
		cout << pos << ". " << amount_t << " " << amount_t2 * -1 << endl;
		pos ++;
	}
	return 0;	
}