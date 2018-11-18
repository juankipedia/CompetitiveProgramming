# include <bits/stdc++.h>
using namespace std;

int main(){
	long long x = 0;
	string ops;
	cin >> ops;
	for (size_t i = 0; i < ops.length(); i += 4){
		if(ops[i] == 'X'){
			if(ops[i + 1] == '+')
				x++;
			else
				x--;
		}
		else if(ops[i] == '+')
			x++;
		else
			x--;
	}

	cout << x << endl;
	return 0;
}